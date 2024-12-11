//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "kartaSieciowa.h"
#include "wlasnyMsg_m.h"
Define_Module(KartaSieciowa);

void KartaSieciowa::wyslijZadanie(std::string brama, cQueue kolejka, WlasnyMsg *zadanie, int gIndex = -1){

    cChannel *channel = gate(brama.c_str(), gIndex)->getTransmissionChannel();
    simtime_t txFinishTime = channel->getTransmissionFinishTime();

    if (txFinishTime <= simTime())
    {
        send(zadanie,brama.c_str(), gIndex);
    }
    else
    {
        waitAndEnqueue(txFinishTime-simTime(),&kolejka);
        send(zadanie,brama.c_str(), gIndex);
    }

}

void KartaSieciowa::activity()
{

    WlasnyMsg *zadanie ;
   // double jednostkowyCzasObslugi =(double) par("jednostkowyCzasObslugi");
    cQueue kolejka;
    while (true)
        {
            if(kolejka.isEmpty())
            {
                zadanie = (WlasnyMsg*)receive();
            }
            else
            {
                zadanie=(WlasnyMsg*)kolejka.pop();
            }

            std::string brama = zadanie->getArrivalGate()->getBaseName();

            int a = brama.compare("odKlienta");

            if(a==0)  // brama.compare("odKlienta")== true
            {
               wyslijZadanie("doSerwera", kolejka, zadanie, -1);
            }
            else
            {
                wyslijZadanie("doKlienta",kolejka,zadanie, zadanie->getSrcAddress());
            }




         }
}

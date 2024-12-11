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

#include "klient.h"
#include "wlasnyMsg_m.h"

Define_Module(Klient);

void Klient::initialize()
{
    statystyki.setName("czasyOpowiedzi");
    cMessage *wlasnaWiadomosc = new cMessage();
    scheduleAt(simTime(),wlasnaWiadomosc);
}

void Klient::handleMessage(cMessage *msg)
{
    //double czasMiedzyZadaniami;


    cPacket *zadanie ;
    if(msg->isSelfMessage())
    {
        zadanie=new cPacket();
       //zadanie->setAdresZrodlowy(1);
        //zadanie->setAdresZrodlowy(2);
        zadanie->setKind((int)par("idKlienta"));
        zadanie->setName("aaaaa");
        //zadanie->setWielkoscZadania((double)par("wielkoscZadania"));
        double wielkoscZadania = (double)par("wielkoscZadania");
        if(wielkoscZadania<100){
            wielkoscZadania=100;
        }
        zadanie->setByteLength((int)wielkoscZadania);
        send(zadanie,"doSerwera");

        double   czasMiedzyZadaniami=(double) par("czasMiedzyZadaniami");

        if(czasMiedzyZadaniami<0)
           {
               czasMiedzyZadaniami = 0;
           }

        scheduleAt(simTime() + czasMiedzyZadaniami,msg);
    }

    else
    {
        double czasOdpowiedzi = msg->getArrivalTime().dbl()-msg->getCreationTime().dbl();
        statystyki.record(czasOdpowiedzi);
        delete msg;
    }
}

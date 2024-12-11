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

#include "procesor.h"
#include "wlasnyMsg_m.h"

Define_Module(Procesor);


void Procesor::activity()
{

    WlasnyMsg *zadanie ;
    double jednostkowyCzasObslugi =(double) par("jednostkowyCzasObslugi");
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

            //Procesor obsługując żądania zużywał 527 μs na wyszukanie danych oraz 240 μs na transmisję każdych 512 B danych do klienta.
            //waitAndEnqueue(0.000527 + jednostkowyCzasObslugi * (zadanie->getWielkoscZadania() / 512), &kolejka);

            std::string brama= zadanie->getArrivalGate()->getBaseName();

            int a = brama.compare("odSerwera");

            if(a==0)  // brama.compare("odSerwera")== true
            {
                //Procesor obsługując żądania zużywał 527 μs na wyszukanie danych
                waitAndEnqueue(0.000527, &kolejka);
                send(zadanie,"doOdDysku$o");
            }
            else
            {
                //oraz 240 μs na transmisję każdych 512 B danych do klienta.
                waitAndEnqueue(jednostkowyCzasObslugi * (zadanie->getWielkoscZadania() / 512), &kolejka);
                send(zadanie,"doSerwera");
            }


         }
}

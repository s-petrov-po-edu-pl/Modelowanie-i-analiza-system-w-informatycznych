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

#include "dysk.h"
#include "wlasnyMsg_m.h"

Define_Module(Dysk);

// void Dysk::initialize()
//{
//     // TODO - Generated method body
// }

void Dysk::activity()
{
    WlasnyMsg *zadanie;
    double jednostkowyCzasObslugi = (double)par("jednostkowyCzasObslugi");
    cQueue kolejka;
    while (true)
    {
        if (kolejka.isEmpty())
        {
            zadanie = (WlasnyMsg *)receive();
        }
        else
        {
            zadanie = (WlasnyMsg *)kolejka.pop();
        }

        //dysk ma być przeszukiwany w celu znalezienia danych w czasie 5ms, czas transmisji danych przez dysk wynosi 410 μs na każde 4KB danych
        waitAndEnqueue(0.005 + jednostkowyCzasObslugi * (zadanie->getWielkoscZadania() / 4096), &kolejka);
        send(zadanie, "doOdProcesora$o");
    }
}

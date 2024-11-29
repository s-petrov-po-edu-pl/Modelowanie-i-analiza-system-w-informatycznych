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
    address = par("address");
    cMessage *wlasnaWiadomosc = new cMessage();
    scheduleAt(simTime(), wlasnaWiadomosc);
}

void Klient::handleMessage(cMessage *msg)
{
    // double czasMiedzyZadaniami;

    WlasnyMsg *zadanie;
    if (msg->isSelfMessage())
    {
        zadanie = new WlasnyMsg();

        zadanie->setSrcAddress(this->address);

        zadanie->setKind(2);
        zadanie->setName("aaaaa");
        int wielkoscZadania = (int)par("wielkoscZadania").doubleValue();
        zadanie->setWielkoscZadania(wielkoscZadania);
        zadanie->setByteLength(wielkoscZadania);
        send(zadanie, "doSerwera");

        double czasMiedzyZadaniami = (double)par("czasMiedzyZadaniami");
        if (czasMiedzyZadaniami < 0)
        {
            czasMiedzyZadaniami = 0;
        }

        scheduleAt(simTime() + czasMiedzyZadaniami, msg);
    }

    else
    {
        delete msg;
    }
}

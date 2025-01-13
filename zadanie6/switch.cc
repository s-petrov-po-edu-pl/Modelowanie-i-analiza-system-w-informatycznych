
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

#include "switch.h"

Define_Module(Switch);
cQueue kolejka;

void Switch::initialize()
{
    // TODO - Generated method body
}

void Switch::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    std::string brama= msg->getArrivalGate()->getBaseName();
    if(brama.compare("bramaKlient")==0){
        send(msg,"bramaSerwer$o",intrand(getParentModule()->par("liczbaSerwerow")));
    }else{

    int idKlienta = msg->getKind();
    send(msg,"bramaKlient$o",idKlienta);
    }
}

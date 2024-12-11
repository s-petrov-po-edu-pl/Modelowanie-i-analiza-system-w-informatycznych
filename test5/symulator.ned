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

network Symulator
{
    parameters:
        @display("bgb=334,237");
    submodules:
        klient1: Klient {

            idKlienta = 1;
            @display("p=56,43");
        }
        klient2: Klient {

            idKlienta = 2;
            @display("p=56,131");
        }
        serwer: Serwer {
            @display("p=265,182");
        }
        switch: Switch;

    connections:
        //serwer do switcha
        switch.doSerwera --> serwer.odKlienta;
        switch.odSerwera <-- serwer.doKlienta;

        //klient1 do switcha
        klient1.doSerwera --> switch.odKlienta1;
        klient1.odSerwera <-- switch.doKlienta1;

        //klient2 do switcha
        klient2.doSerwera --> switch.odKlienta2;
        klient2.odSerwera <-- switch.doKlienta2;



}

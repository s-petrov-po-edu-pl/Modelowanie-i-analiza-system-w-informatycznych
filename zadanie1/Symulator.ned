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

//
// TODO auto-generated type
//
network Symulator
{
    @display("bgb=414,330");
    submodules:
        Host1: Klient {
            parameters:
                //wielkosc_danych = lognormal(40,5,0);
                //czas_namyslu = exponential(0.5);
                @display("p=83,107;i=device/pc4");
        }
        Komputer: Serwer {
            @display("p=235,145;i=device/server2");
        }
        Host2: Klient {
            parameters:
                //wielkosc_danych = lognormal(40,5,0);
                //czas_namyslu = exponential(0.5);
                @display("p=83,224;i=device/pc4");
        }
    connections:
        //Host1.oddo_klienta <--> Komputer.oddo_komputera;
        Host1.od_klienta --> Komputer.od_komputera1;
        Host1.do_klienta <-- Komputer.do_komputera1;
        //Host2.oddo_klienta <--> Komputer.oddo_komputera;
        Host2.od_klienta --> Komputer.od_komputera2;
        Host2.do_klienta <-- Komputer.do_komputera2;
}

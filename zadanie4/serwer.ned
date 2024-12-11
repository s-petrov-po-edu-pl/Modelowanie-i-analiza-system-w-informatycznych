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

module Serwer
{
    parameters:

        @display("bgb=260,127;i=device/server2");
    gates:
        input odKlienta;
        output doKlienta;
    submodules:
        cpu: Procesor {
            // 240 μs na transmisję każdych 512 B danych do klienta.
            jednostkowyCzasObslugi = 240e-6;
            @display("p=39,42");
        }
        hdd: Dysk {
            //czas transmisji danych przez dysk wynosi 410 μs na każde 4KB danych
            jednostkowyCzasObslugi = 410e-6;
            @display("p=127,44");
        }
    connections:
        odKlienta --> cpu.odSerwera;
        doKlienta <-- cpu.doSerwera;


        hdd.doOdProcesora <--> cpu.doOdDysku;

}

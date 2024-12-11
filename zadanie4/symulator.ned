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
        @display("bgb=462,328");
    submodules:
        klient1: Klient {
            parameters:
                address = 0;
                @display("p=56,69");
                //częstotliwość, z jaką klienci będą wysyłali żądania była rozkładem wykładniczym o wartości oczekiwanej 0,2s
                czasMiedzyZadaniami = exponential(0.2);
                //wielkość danych, które będą żądali był rozkładem normalnym z wartością oczekiwaną μ=5000B i wariancją σ2=333B
                wielkoscZadania = normal(5000, sqrt(333));
        }

        klient2: Klient {
			parameters:
                address = 1;
                @display("p=56,246");
                //częstotliwość, z jaką klienci będą wysyłali żądania była rozkładem wykładniczym o wartości oczekiwanej 0,2s
                czasMiedzyZadaniami = exponential(0.2);
                //wielkość danych, które będą żądali był rozkładem normalnym z wartością oczekiwaną μ=5000B i wariancją σ2=333B
                wielkoscZadania = normal(5000, sqrt(333));
        }


        serwer: Serwer {
            @display("p=388,176");
        }

        router: KartaSieciowa {
            parameters:
            	@display("p=217,166");
            gates:
                odKlienta[2];
                doKlienta[2];
                
        }

    connections:

        klient1.doSerwera --> router.odKlienta[0];
        //klient1.odSerwera <-- router.doKlienta[0];
        klient1.odSerwera <-- {  datarate = 100Mbps; } <-- router.doKlienta[0];
        
        klient2.doSerwera --> router.odKlienta[1];
        //klient2.odSerwera <-- router.doKlienta[1];
        klient2.odSerwera <-- {  datarate = 100Mbps; } <-- router.doKlienta[1];
        
        router.doSerwera --> {  datarate = 100Mbps; } --> serwer.odKlienta;
        //router.doSerwera --> serwer.odKlienta;
        router.odSerwera <-- serwer.doKlienta;




}

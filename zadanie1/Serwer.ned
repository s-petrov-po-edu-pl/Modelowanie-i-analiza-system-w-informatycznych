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
network Serwer
{
    @display("bgb=481,227");
    gates:
        //inout oddo_komputera;
        input od_komputera1;
        output do_komputera1;
        
        input od_komputera2;
        output do_komputera2;
        
        
    submodules:
        cpu: Processor {
            @display("p=146,109;is=vl");
        }
        dysk: Dysk_twardy {
            @display("p=320,109");
        }
   connections:
		//oddo_komputera <--> cpu.oddo_klienta;
		do_komputera1 <-- cpu.do_klienta1;
		do_komputera2 <-- cpu.do_klienta2;
		
		od_komputera1 --> cpu.od_klienta1;
		od_komputera2 --> cpu.od_klienta2;
		
		
		//cpu.oddo_dysku <--> dysk.oddo_procesora;
		cpu.do_dysku --> dysk.od_procesora;
		cpu.od_dysku <-- dysk.do_procesora;
}

//*****************************************************************************
// www.orahyn.com
// Copyright [2013] Orahyn (Pvt) Ltd.
// Licensed under the Apache License, Version 2.0 (the "License"); you may not 
// use this file except in compliance with the License. You may obtain a copy 
// of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software 
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT 
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the 
// License for the specific language governing permissions and limitations 
// under the License.

// Date:      01/07/13
// Description: Dual Port SRAM. Equivelant to Xilinx RAM 
//
//*****************************************************************************
  #include "RAMB4_S8.h"
 
  /****************************************************************************
   Logic for memory
  ****************************************************************************/ 
  
  // Memory Write Block 
  // Write Operation : When we = 1, en = 1
  void RAMB4_S8::write_memp () {
  sc_uint <9> addra_int = ADDR.read(); // tmp - Visual C++ compile correctly wihti this junk line
    if (EN.read() & WE.read()) {
      mem[ADDR.read()] = DI.read();
    }
  }

  // Memory Read Block 
  // Read Operation : When EN = 1
  void RAMB4_S8::read_memp () {
    if (EN.read())  {
      DO.write(mem[ADDR.read()]);
    }
  }

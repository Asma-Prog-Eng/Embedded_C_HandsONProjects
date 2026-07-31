Bare metal implementation  of an I2C driver for STM32 development board 
## Features
I2C1 initialization with clock frequency set to  100 KHz.
## Requirements
### Hardware
- Discovery STM32 development board (STM32F411x series)
- Multimeter (optional for debugging)
- AZ-Delivery Logic Analyzer (optional for debugging)
- DS3231 RTC peripheral , wires to connect the RTC device to STM32 board
  
### Software
- STM32CubeIDE or compatible toolchain
- PulseView (Optional for Debugging)
  
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/2C_DS3231_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : GPIO_I2C_init(), I2C_init() <br />
Read data in DS323 RTC device, located in register of address 0x00 : read_Byte( DS323_ADDR, 0x00, &data) :  <br />
LED is toggled every second :
if( data & 1){
    GPIOD->ODR ^= (1U <<12);
}
## Project Structure

├── Core<br />
├── Inc<br />  → I2C.h <br />
├── Src<br /> → I2C.c<br /> → main.c

## Troubleshooting

LED is not toggling: <br />
- Verify voltage level at VCC pin (of RTC), should be connected to 3V pin of STM32 board <br />

## Known Limitations
Limited to 8-bit data words

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License <br />
Copyright (c) [2025] [Asma Askri]

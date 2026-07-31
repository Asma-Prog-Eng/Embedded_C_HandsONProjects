Bare metal implementation  of a  UART driver for STM32 development board 
## Features
UART2 initialization with tested baud rates (1200, 4800, 9600 ,115200) and peripheral clock = 8MHz.
## Requirements
### Hardware
- Nucleo STM32 development board (STM32F303x series)
- Multimeter (optional for debugging)
- External LED connected to PB7 (Optional , User LED can be used)
- Bread Board (Optional if  User LED will be used)
  
### Software
- STM32CubeIDE or compatible toolchain
- RealTerm
  
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/UART_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : UART2_init () <br />
Transmitting Data : a character is entered through RealTerm terminal <br />
Receiving Data: uart2_read() 
Transmitting the receiveed Data back to RealTerm to be displayed
If key 1 is pressed then LED connected to PB7 is switched on

## Project Structure

├── Core<br />
├── Inc<br />  → uart.h <br />
├── Src<br /> → uart.c<br /> → main.c

## Troubleshooting

No data received: <br />
- Verify baud rate settings <br />
- Check TX/RX pin connections <br />
- Ensure correct clock configuration <br />

Garbage characters: <br />
- Verify clock source accuracy <br />
- Check voltage levels <br />
- 
Overrun errors: <br />
- Increase receive buffer size <br />

## Known Limitations
Limited to 8-bit data words

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License <br />
Copyright (c) [2025] [Asma Askri]

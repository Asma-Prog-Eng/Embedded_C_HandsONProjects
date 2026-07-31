Bare metal implementation of an Output Compare Timer Driver  for STM32 development board 
## Features
- TIMER2 initialization with peripheral clock = 16MHz.
- Configurable delay mode : in Hz or in s
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
- External LED connected to PA5
- Bread Board 
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/GPIO_Interrupt_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization :  GPIOA_Init() , Timer2_output_compare_init(5, 'h')
While loop : Toggle LED on PA5 at a frequency of 5 Hz

## Project Structure

├── Core<br />
├── Inc<br />  → Timer.h <br />
├── Src<br /> →  Timer.c<br /> → main.c

## Troubleshooting

LED on PA5 is not toggling : <br />
- Verify Pin mode (GPIOD->MODER) configuration <br />
  
## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]

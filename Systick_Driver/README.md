Bare metal implementation  of a Systick driver for STM32 development board 
## Features
- Systick initialization with system clock = 8MHz.
- TON/OFF delay to toggle user LED3 (PD13) (TON = 1s, TOFF = 2s)
  
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/Systick_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : Systick_init() ,  GPIOD_init() <br />
Delay configuration  : Delay_configuration <br />
TON/OFF delay : LED_toggle() <br />

## Project Structure

├── Core<br />
├── Inc<br />  → Systick.h <br />
├── Src<br /> → Systick.c<br /> → main.c

## Troubleshooting

User LED3 is OFF:
- Verify clock source for systick peripheral (SysTick->CTRL register)
- Verify clock access for port D (RCC->AHB1ENR register)
- Verify PD13 mode, should be configured to output mode (GPIOD->MODER)
  
## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]

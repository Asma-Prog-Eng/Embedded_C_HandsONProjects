Bare metal implementation  of an GPIO output driver , with PLL clock configuration ,for STM32 development board 
## Features
- GPIOA initialization with peripheral clock = 50MHz.
- PLL clock configuration for GPIOA
- Pin PA5 is configured as digital output
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
- AZ-Delivery Logic Analyzer (optional for debugging)
- External User LED (optional, integrated user LED can be used)
- Bread Board (optional, only if External User LED is used)
### Software
- STM32CubeIDE or compatible toolchain
- Pulseview
  <img width="1444" height="659" alt="image" src="https://github.com/user-attachments/assets/c2d4bd2f-52e4-4ceb-a01d-ebe89d574497" />

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/GPIO_Output_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
- Initialization : GPIOA_Init() <br />
- Toggle led connected to PA1 : Led_toggle()

## Project Structure

├── Core<br />
├── Inc<br />  → GPIOA_Output.h <br />
├── Src<br /> →  GPIOA_Output.c <br /> → main.c

## Troubleshooting

No value could be read from on ADC1->DR: <br />
- Verify clock acess for GPIOA peripheral (RCC->APHBENR register) <br />
- Verify PA5 mode, should be set as output (GPIOA->MODER register)

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]

Bare metal implementation of a GPIO Interrupt Driver  for STM32 development board 
## Features
- GPIO initialization with peripheral clock = 16MHz.
- Interrupt handlling for GPIOA line 0
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
- External LED (optional)
- Push button (optioanl)
- Bread Board (optional)
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
Initialization :  GPIO_Init(), exti_0_Init()
Interrupt handling : EXTI0_IRQHandler() 
Toggle LED4 : exti_callback()

## Project Structure

├── Core<br />
├── Inc<br />  → GPIO_Interrupt.h <br />
├── Src<br /> →  GPIO_Interrupt.c<br /> → main.c

## Troubleshooting

No value could be read from on ADC1->DR:
- Verify clock acess for ADC1 peripheral (RCC->APB2ENR register)
- Verify clock acess for port A (RCC->APHBENR register)
- Verify PA1 mode, should be configured to analog mode (GPIOA->MODER)
  
## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]

# Bare-Metal ADC Driver for STM32
Bare-metal implementation of an ADC driver for an STM32 development board.
## Features
- **ADC1 Initialization:** Configured with tested ADC resolutions (6-bit, 8-bit) and peripheral clock at 8 MHz.
- **Single Conversion Mode**
- **Interrupt Handling**
---
## Requirements

### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
- Potentiometer ( input Voltage = 3V)
  
### Software
- STM32CubeIDE or compatible toolchain
---
## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Asma-Prog-Eng/ADC_Interrupt_Driver

2. Import project into STM32CubeIDE:
Go to File → Import... → Existing Projects into Workspace

3. Update CMSIS Include Path:
- Go to Project Properties $\rightarrow$ C/C++ General $\rightarrow$ Paths and Symbols (or Includes).
- Delete the existing CMSIS path directory.
- Add the path to the project's local CMSIS folder: Add... $\rightarrow$ File System...
4. Rebuild project dependencies:
Right-click the project in the Explorer and select Clean Project, then Build Project.

## Usage
Initialization:
- GPIO_init();
- ADC1_init();
- start_conversion();

Reading & Converting Values:
- ADC_IRQHandler();
- adc_callback();

## Project Structure

├── Core/
├── Inc/
│   └── ADC.h
└── Src/
    ├── ADC.c
    └── main.c

## Troubleshooting
If no value is read from ADC1->DR:
- Verify clock access for the ADC1 peripheral (RCC->APB2ENR register).
- Verify clock access for GPIO Port A (RCC->AHB1ENR register).
- Verify PA1 pin mode is configured as Analog Mode (GPIOA->MODER).
- Verify that the ADC1 interrupt is enabled in the NVIC (NVIC_EnableIRQ).

## Known Limitations
Currently limited to 8-bit resolution mode.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
MIT License — Copyright (c) 2025 Asma Askri

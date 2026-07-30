Bare metal implementation  of an ADC driver ,in continuous mode conversion with PLL clock configuration ,for STM32 development board 
## Features
- ADC initialization with tested ADC resolution (6-bits, 8-bits) and peripheral clock = 50MHz.
- PLL clock configuration for ADC
- Continuous conversion modes
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
- Potentiometer ( input Voltage = 3V)
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/ADC_PLL_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : ADC1_init () 
Define ADC resolution : ADC_resolution_calculation(ADC_bit_resolution)
Read raw value : ADC1_read()
Covert raw value into voltage

## Project Structure

├── Core<br />
├── Inc<br />  → ADC.h <br />
├── Src<br /> → ADC.c<br /> → main.c

## Troubleshooting

No value could be read from on ADC1->DR:
- Verify clock acess for ADC1 peripheral (RCC->APB2ENR bit)
- Verify clock acess for port A (RCC->APHBENR bit)
- Verify PA1 mode (GPIOA->MODER ; bits 2:3 (0x3))

## Known Limitations
Limited to 8-bits resolution

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]

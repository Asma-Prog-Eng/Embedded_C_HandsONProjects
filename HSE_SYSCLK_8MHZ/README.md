# HSE_SYSCLK_8MHZ
Configure HSE as clock source using HAL APIs and print the relevant clock frequencies in the serial terminal,  for STM32 development board
## Features
UART2 initialization with baud rate = 115200 bps <br />
SYSCLK is configured to 8 MHZ <br />
AHB clock as 4 MHZ <br />
APB1 clock as 2 MHZ <br />
APB2 clock as 2 MHZ<br />
## Requirements
Hardware <br />
Nucleo STM32 development board (STM32F103x series) <br />
Software <br />
STM32CubeIDE or compatible toolchain <br />
Tera Term 
## Installation
Clone this repository:

git clone https://github.com/Asma-Prog-Eng/HSE_SYSCLK_8MHZ  <br />
Import project into STM32CubeIDE: <br /> File → Import... → Existing Projects into Workspace  <br />
Rebuild project dependenciesFile
## Usage
Initialization : UART2_init (), HAL_init()  <br />
SYSCLK configuration : SYSCLK_Config() <br />
Display the new enabled clk freqeuncies : Print_Freq() <br />
Send data to the serial terminal : HAL_UART_Transmit()  <br />
Restart the program by reseting the board : while(1) {;}
## Project Structure
├── Core <br />
├── Inc <br />
→ it.h <br />
→ main_app.h <br />
→ msp.h <br />
→ stm32321f1xx.hal.h <br />
├── Src <br />
→ it.c <br />
→ main_app.c <br />
→ msp.c. <br />
→ syscall.c <br />
→ sysmem.c <br />
→ system_stm32f1xx.c <br />

## Troubleshooting
Row data received: <br />
Check the implemented prescalers: RCC_SYSCLK_DIV2 <br />
## Known Limitations
Prescalers ( Exp: RCC_SYSCLK_DIV2 ) and  waiting cycles ( FLASH_ACR_LATENCY_0)  <br /> 
can only be updated manually
## Contributing
Pull requests are welcome. For major changes, open an issue first.
License
MIT License
Copyright (c) [2026] [Asma Askri]

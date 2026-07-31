# 🔌 Embedded C Hands-On Projects

Welcome to my **Embedded C Hands-On Projects** repository! This repository serves as a centralized monorepo containing various bare-metal drivers, microcontroller peripheral implementations, and code challenges exercises written in C.

---

## 📁 Repository Directory

Below is an overview of all the project folders inside this repository. Click on any project name to jump directly to its source code:

| Folder / Project Name | Description | Target Hardware / Platform |
| :--- | :--- | :--- |
| **[`ADC_Interrupt_Driver`](./ADC_Interrupt_Driver/)** | *Bare metal ADC Driver in Interrupt mode Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`ADC_PLL_Driver`](./ADC_PLL_Driver/)** | *ADC Driver bare metal Implementation, PLL Clock Configuration* | *STM32F103 / ARM Cortex-M3* |
| **[`Client_Server_Socket`](./Client_Server_Socket/)** | *Basic Server-Client Socket Communication* | *CodeBlocks / Git bash* |
| **[`GPIO_Interrupt_Driver`](./GPIO_Interrupt_Driver/)** | *Bare metal GPIO Interrupt Handling* | *STM32F411x  / ARM Cortex-M4* |
| **[`GPIO_Output_Driver`](./GPIO_Output_Driver/)** | *Bare metal GPIO Output Driver in polling mode Implementation* | *STM32F411x  / ARM Cortex-M4* |
| **[`HSE_SYSCLK_8MHZ`](./HSE_SYSCLK_8MHZ/)** | *HSE Clock Configuration and clock frequency validation* | *STM32F103 / ARM Cortex-M3* |
| **[`I2C_DS3231_Driver`](./I2C_DS3231_Driver/)** | *Bare metal I2C Driver Implementation* | *STM32F411x  / ARM Cortex-M4* |
| **[`InputCapture_Timer_Driver`](./InputCapture_Timer_Driver/)** | *Bare metal InputCapture_Timer_Driver Implementation* | *STM32F4 / ARM Cortex-M4* |
| **[`Multi-Threading`](./Multi-Threading/)** | *Safe Code Thread impementation* | *CodeBlocks / Git bash* |
| **[`OutputCompare_Timer_Driver`](./OutputCompare_Timer_Driver/)** | *Bare metal Output Compare Timer Driver*  | *STM32F411x  / ARM Cortex-M4* |
| **[`PLL_SYSCLK_HSI`](./PLL_SYSCLK_HSI/)** | *SYSCLK Configuration using PLL* | *STM32F103 / ARM Cortex-M3* |
| **[`SPI_ADXL345_DRIVER`](./SPI_ADXL345_DRIVER/)** | *ADXl345 accelerometer data monitoring using SPI* | *STM32F411x  / ARM Cortex-M4* |
| **[`SYSTICK_DRIVER`](./SYSTICK_DRIVER/)** | *SYSTICK Driver Implementation* | *STM32F411x  / ARM Cortex-M4* |
| **[`SPI_ADXL345_DRIVER`](./SPI_ADXL345_DRIVER/)** | *ADXl345 accelerometer data monitoring using SPI* | *STM32F411x  / ARM Cortex-M4* |
| **[`PLL_SYSCLK_HSI`](./PLL_SYSCLK_HSI/)** | *SYSCLK Configuration using PLL* | *STM32F103 / ARM Cortex-M3* |
| **[`SYSCLK_Driver`](./SYSCLK_Driver/)** | *SYSCLK Driver Implementation in polling mode* | *STM32F411x / ARM Cortex-M4* |
| **[`Systick_Interrupt_Driver`](./Systick_Interrupt_Driver/)** | *Super Loop Systick Driver Implementation* | *STM32F411 / ARM Cortex-M4* |
| **[`TIM2-HAL-Interrupt-Overhead-Benchmark`](./TIM2-HAL-Interrupt-Overhead-Benchmark/)** | *Timer 2 Driver in Dual Channel mode Implementation*| *STM32F103 / ARM Cortex-M3* |
| **[`Timer_Driver`](./Timer_Driver/)** | *Bare Metal Timer 2 Driver Implementation* | *STM32F411x  / ARM Cortex-M4* |
| **[`Timer_Interrupt_Driver`](./Timer_Interrupt_Driver/)** | *Bare Metal Timer 2 Driver with Interrupt Handling Implementation*| *STM32F411x  / ARM Cortex-M4* |
| **[`UART_Driver`](./UART_Driver/)** | *Bare Metal UART Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`UART_Example_IT`](./UART_Example_IT/)** | *Super Loop Bare Metal UART Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`UART_Rx_Interrupt_Driver`](./UART_Rx_Interrupt_Driver/)** | *Super Loop UART Receiver Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`stm32-hardware-pwm-led-dimmer`](./stm32-hardware-pwm-led-dimmer/)** | *PWM Mode TIMER 2 Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`stm32-multi-channel-waveform-generator`](./stm32-multi-channel-waveform-generator/)** | *TIMER2 Based Waveform Generator Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`stm32-timer-input-capture-measurement`](./stm32-timer-input-capture-measurement/)** | *Input-Capture Mode TIMER2 Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`stm32-timer-interrupt-led`](./stm32-timer-interrupt-led/)** | *Super Loop TIMER2 Driver Implementation* | *STM32F103 / ARM Cortex-M3* |
| **[`stm32-timer-led-toggle`](./stm32-timer-led-toggle/)** | *TIMER2 Driver, in polling mode, Implementation*  | *STM32F103 / ARM Cortex-M3* |
--- 

## 🛠️ Toolchain & Environment

* **Programming Language:** Embedded C (C99 / C11 standards)
* **Architectures:** ARM Cortex-M, RISC-V 
* **IDEs & Compilers:** GCC ARM Toolchain, GIT BASH, STM32CubeIDE, CodeBlocks
* **Hardware Tools:** ST-LINK, Logic Analyzers, Multimeter

---

## 🚀 How to Run & Build

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Asma-Prog-Eng/Embedded_C_HandsONProjects.git

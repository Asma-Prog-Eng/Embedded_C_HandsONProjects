# STM32 Timer Input Capture Measurement & Signal Validation

An embedded instrumentation project utilizing dual hardware timers on an **STM32F103** microcontroller to demonstrate high-speed **Input Capture Mode**. One timer acts as a precise signal generator, while a second timer operates as a measurement instrument to capture, calculate, and transmit live frequency telemetry back to a computer over UART.

## 🚀 Project Features
* **High-Speed Clock Configuration:** Driven by a **52 MHz System Clock (SYSCLK)** derived from the Internal High-Speed oscillator (HSI) passed through the PLL (`8 MHz / 2 * 13 = 52 MHz`).
* **Advanced Bus Gating:** Bus prescalers are configured as `AHB=1`, `APB1=4`, and `APB2=4`. Due to the internal architecture of the STM32F1 clock tree, the APB1 timer multiplier ($\times 2$) engages automatically, supplying **Timer 2 and Timer 3 with a dedicated 26 MHz clock base**.
* **Precise Signal Generation (TIM2):** Configured to execute a periodic interrupt precisely every 40 µs, toggling pin **PA7** to yield a rock-solid **12.5 kHz** test square wave.
* **Hardware Input Capture (TIM3):** Configured on Channel 2 (**PA10**) to monitor the generated signal, capturing consecutive rising edges to dynamically parse frequency and period over a 38.46 ns clock-tick resolution.
* **Live Telemetry Engine:** Utilizes background data formatting combined with blocking UART transmission handlers to stream calculated float values to a serial terminal emulator in real-time.

## 🛠️ Hardware & Tools
* **Microcontroller:** STM32F103 (ARM Cortex-M3)
* **System Clock:** 52 MHz
* **Timer Base Clock:** 26 MHz (1 timer tick = 38.46 nanoseconds)
* **IDE:** STM32CubeIDE (GCC Compiler with `-u _printf_float` linked)
* **Measurement Tool:** USB Logic Analyzer paired with **Saleae Logic 2** software

---

## 📊 Logic Analyzer Verification

To verify the signal generation logic before evaluating the Input Capture registers, the raw output on pin **PA9** was recorded using a digital logic analyzer:

### Output Waveform Metrics (PA9)
* **Measured Period:** **80.083 µs** total ($40\ \mu\text{s HIGH} + 40\ \mu\text{s LOW}$ phases)
* **Measured Frequency:** **12.487 kHz**
* **Duty Cycle:** **49.95%** (Captured via Saleae Logic 2)
<img width="1857" height="621" alt="image" src="https://github.com/user-attachments/assets/07f1fa6a-4c91-4891-ac7a-e6b2cc8fb559" />


### 🧮 Input Capture Resolution Math
With the internal timer peripherals running at 26 MHz, each timer count tick represents exactly:
$$\text{Tick Resolution} = \frac{1}{26,000,000\text{ Hz}} = \mathbf{38.46\text{ nanoseconds}}$$

When Timer 3 captures a full 80 µs period of this 12.5 kHz signal, the delta between two consecutive captured rising edges in the `TIM3->CCR2` register translates mathematically to:
$$\text{Expected Capture Delta} = \frac{80\ \mu\text{s}}{38.46\text{ ns}} = \mathbf{2,080\text{ timer counts}}$$

---
### Expected Console Output
Frequency of the signal applied = 12500.000000 Hz
<img width="823" height="543" alt="image" src="https://github.com/user-attachments/assets/0622d0b1-d99e-453c-9522-962681234a17" />

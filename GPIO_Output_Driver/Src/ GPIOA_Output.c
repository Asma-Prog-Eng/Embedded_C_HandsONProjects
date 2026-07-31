
#include "GPIOA_Output.h"
#include "stm32f4xx.h"

#define RCC_GPIOAEN         (1U << 0)

#define RCC_CR_HSIONEN        (1U << 0)

#define RCC_CR_PLLONEN        (1U << 24)

#define RCC_PLLCFGR_PLLQEN    (1U << 26)

#define RCC_PLLCFGR_PLLMEN    (1U << 2)

#define RCC_PLLCFGR_PLLN_1EN    (1U << 6)

#define RCC_PLLCFGR_PLLN_2EN    (1U << 7)

#define RCC_PLLCFGR_PLLPEN      (1U << 0)

void GPIOA_Init(void) {

 /************************Configure ADC PIO pin*******************************************/


	// Configure PLL as clock source

	// Enable HSI ( internal RC oscillator, 8 MHZ) as PLL clock source

	 RCC->CR |= RCC_CR_HSIONEN;

	// Configure PLLM and so  VCO input frequency  = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63


	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLMEN ; // VCO input frequency = 2 Mhz

	// Configure PLLIN and so  VCO output frequency = VCO input frequency × PLLIN  with  50 ≤ PLLIN ≤ 432

	// set PLLIN to 96 , VCO output frequency = 2 * 96 = 192 Mhz

	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_1EN ;
	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_2EN ;

    // Configure PLLP:  PLL output clock frequency = VCO frequency(192 Mhz) / PLLP (!!not to exceed 100MHz !!)


	RCC->PLLCFGR |= RCC_PLLCFGR_PLLPEN ;  // 192 /4 = 48 Mhz

	// Configure PLLQ (  USB OTG FS Fclock = 48 MHz)

	 RCC->PLLCFGR |= RCC_PLLCFGR_PLLQEN;

	 // enable PLL

	  RCC->CR |= RCC_CR_PLLONEN;

	// enable clock access for port A ( PA1)

    RCC->AHB1ENR |= RCC_GPIOAEN ;

	// set PA5 mode to output (0x1 = 10:11)

	GPIOA->MODER |= (1U << 10);

	GPIOA->MODER &= ~(1U << 11);


}


void LED_toggle(void) {

	// set PA5 high

	GPIOA->ODR |= (1U << 5) ;

	// simple delay

	for (volatile uint32_t i = 0; i < 500000; i++) {};

	// set PA5 low

	GPIOA->ODR &= ~(1U << 5) ;

	// simple delay

	for (volatile uint32_t i = 0; i < 500000; i++) {};
}


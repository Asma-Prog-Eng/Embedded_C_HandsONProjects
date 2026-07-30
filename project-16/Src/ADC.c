
#include "stm32f4xx.h"
#include <stdio.h>
#include "ADC.h"


#define RCC_ADC1EN            (1U << 8 )

#define RCC_GPIOAEN             (1U << 0)

#define ADC_SREOC               (1U << 1)

#define ADC_CR2ADON             (1U << 0)

#define ADC_SQR3SQ1             (1U  << 0)

#define ADC_SQR1L               (1U << 20)

#define ADC_CR2SWSTART          (1U << 30)

#define RCC_CR_HSIONEN          (1U << 0)

#define RCC_CR_PLLONEN          (1U << 24)

#define RCC_PLLCFGR_PLLQEN      (1U << 26)

#define RCC_PLLCFGR_PLLMEN      (1U << 2)

#define RCC_PLLCFGR_PLLN_1EN    (1U << 6)

#define RCC_PLLCFGR_PLLN_2EN    (1U << 7)

#define RCC_PLLCFGR_PLLPEN      (1U << 0)

#define ADC_CR2_CONTEN           (1U << 1)

void ADC1_Init(void) {

 /************************Configure ADC PIO pin*******************************************/


	// Configure PLL as clock source

	// Enable HSI ( = 8 MHZ) as PLL clock source

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

	// ADCLOCK = APB2CLOCK /2 = 50 Mhz ( default ADCCLK prescaler = 2 )

	// Can be checked in ADC common register : bit ADCPRE

	 // enable PLL

	  RCC->CR |= RCC_CR_PLLONEN;

	// enable clock access for port A ( PA1)

    RCC->AHB1ENR |= RCC_GPIOAEN ;

	// configure PA1 pin mode to analog

   GPIOA->MODER |= (0x3 << 2);


/*************************Configure ADC parameters *************************************/

	// enable clock access for ADC periph

    RCC->APB2ENR |= RCC_ADC1EN;

	// configure conversion sequence start :  single conversion- channel 1 (ADC1_1)

    ADC1->SQR3 |= ADC_SQR3SQ1;


	// configure senquence length to 1 conversion

    ADC1->SQR1 &=~ADC_SQR1L ;

    // enable continuous mode conversion

    ADC1->CR2 |= ADC_CR2_CONTEN ;

	// enable ADC periph

    ADC1->CR2 |= ADC_CR2ADON;


}

uint16_t ADC1_read(void ) {


	// start conversion

	ADC1->CR2  |= ADC_CR2SWSTART ;

	// wait till conversion is done

	while (!(ADC1->SR & ADC_SREOC)) {};

	// simple delay

	for (volatile uint32_t i = 0; i < 5000000; i++){};
	// read data register

   return (ADC1->DR & 0xFF);


}

int ADC_resolution_calculation(int ADC_bit_resolution ) {

	int result = 1;

	int temp = ADC_bit_resolution ;

	while ( temp > 0) {

		    result *= 2;
			temp -=1;
	}

	return result;
}



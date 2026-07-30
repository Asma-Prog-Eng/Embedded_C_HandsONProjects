
#include "stm32f4xx.h"
#include "ADC.h"


#define ADC1_EN          (1U << 8 )

#define GPIODEN             (1U << 3)

#define GPIOAEN         (1U << 0)

#define GPIOD_MODER_1   (1U << 24)

#define GPIOD_MODER_2   (1U << 25)


#define CR2_ADON         (1U << 0)

#define ADC_SQR3SQ1         (1U  << 0)

#define ADC_SQR1L           (1U << 20)

#define  CR1_EOCIE        (1U << 5)


void ADC1_Init(void) {



/*************************Configure ADC parameters *************************************/


   // disable global interrupts

    __disable_irq();

	 ADC1->CR2 &= ~CR2_ADON;

	 // enable clock access for ADC periph

	 RCC->APB2ENR |= ADC1_EN;


   // enable interrupt for adc1

	 ADC1->CR1 |= CR1_EOCIE;


	// configure conversion sequence start :  single conversion- channel 1 (ADC1_1)

    ADC1->SQR3 |= ADC_SQR3SQ1;


	// configure senquence length to 1 conversion

    ADC1->SQR1 &=~ADC_SQR1L ;

    // Enable ADC1 interrupt  in NVIC

    NVIC_EnableIRQ(ADC_IRQn);

    // enable global interrtupts

    __enable_irq();


	// enable ADC periph

    ADC1->CR2 |= CR2_ADON;


}

void start_conversion(void) {


	// enable continuous mode

	ADC1->CR2 |= (1U << 1);

	// start adc conversion

    ADC1->CR2  |= (1U << 30) ;


}


void GPIO_init(void) {

	 /************************Configure ADC PIO pin*******************************************/

		// enable clock access for port A ( PA1)

	    RCC->AHB1ENR |=( GPIOAEN |  GPIODEN ) ;

		// configure PA1 pin mode to analog

	   GPIOA->MODER |= (0x3 << 2);

	/*************************Configure LED PD12 pin********************************************/

	// set PD12 pin mode to digital output : 01

	 GPIOD->MODER |= GPIOD_MODER_1;

	 GPIOD->MODER &= ~GPIOD_MODER_2;
}

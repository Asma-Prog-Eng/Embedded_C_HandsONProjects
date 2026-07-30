
#include "stm32f4xx.h"


#include "GPIO_Interrupt.h"


#define GPIODEN         (1U << 3)

#define GPIOAEN         (1U << 0)

#define GPIOD_MODER_1   (1U << 24)

#define GPIOD_MODER_2   (1U << 25)

#define SYSCFG_EXTICR0  (1U << 0)

#define RCC_SYSCFGEN    (1U << 14)

#define EXTI_IMR         (1U << 0)

#define EXTI_RSTSR       (1U << 0)


void exti_0_Init(void) {

	// disable global interrupts

	__disable_irq();

	 // enable clock acess to system configuration controller

	RCC->APB2ENR |= RCC_SYSCFGEN ;

	// unmask EXTI0

	EXTI->IMR |= EXTI_IMR ;

	// select trigger type : rising edge

	EXTI->RTSR |= EXTI_RSTSR ;

	// PORTA for EXTI0

	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR0;

	// Enable EXTI0 line in NVIC

      NVIC_EnableIRQ(EXTI0_IRQn);

	// enable global interrupts

	__enable_irq();
}


void GPIO_Init(void) {


	// enable clock access to Port D and A

	 RCC->AHB1ENR |= (GPIODEN | GPIOAEN ) ;

	// set PD12 pin mode to digital output : 01

	 GPIOD->MODER |= GPIOD_MODER_1;

	 GPIOD->MODER &= ~GPIOD_MODER_2;

}

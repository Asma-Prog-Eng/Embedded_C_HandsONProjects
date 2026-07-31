
#include "stm32f4xx.h"
#include "Systick.h"


#define SYST_CTRL_CLKSOURCE     (1U << 2)

#define SYST_CTRL_ENABLE               (1U << 0)

#define SYST_CTRL_COUNTFLAG        (1U << 16)

#define RCC_GPIOD_EN              (1U <<3)

#define GPIOD_MODER_1             (1U << 26)

#define GPIOD_MODER_2             (1U << 27)

#define LED_PIN                    13

#define SysClock                   8000000UL

void Systick_init(void){


	// enable clock source process clock

	SysTick->CTRL |= SYST_CTRL_CLKSOURCE;


}


void Delay_configuration(int delay_s){

	// write value to load register N = delay_s * SysClock , SysClock = 16Mhz

	int  N = delay_s * SysClock;

	SysTick->LOAD |= (N -1);

	// Clear sytick current value register

	SysTick->VAL = 0;

	// enable counter

	SysTick->CTRL |= SYST_CTRL_ENABLE;

    // wait till counting is done
	while (!(SysTick->CTRL & SYST_CTRL_COUNTFLAG )) {};

	// disable counter

	SysTick->CTRL &= ~SYST_CTRL_ENABLE;

}


void GPIOD_init(void) {

	// enable clock access to port D

	RCC->AHB1ENR |= RCC_GPIOD_EN ;

	// set PD13 mode to output

   GPIOD->MODER |=  GPIOD_MODER_1 ;

   GPIOD->MODER &=  ~GPIOD_MODER_2 ;

}


void LED_toggle(void) {

	// set PD13 high

	GPIOD->ODR |= (1U << LED_PIN );

	// delay of 1s

	Delay_configuration(1);


	// set PD13 low

	GPIOD->ODR &= ~(1U << LED_PIN );

	// delay of 2s

	Delay_configuration(1);

}




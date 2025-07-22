/****************************************************************
 * Bare metal implementation of a Systick interrupt Driver
 * toggle User LED3 every 1s
 ****************************************************************/

#include "stm32f4xx.h"

#include "Systick.h"

static void systick_callback(void) ;

int main(void){

	 GPIOD_init();

	 Delay_1s_configuration(1);

	 Systick_interrupt_init();

	while(1) {



	}

}

// static so that it can be only accessed here

static void systick_callback(void) {


	// set PD13 high

	GPIOD->ODR ^= (1U << LED_PIN );


}


void SysTick_Handler(void) {


	//check for end of counting

	if (SysTick->CTRL & CTRL_COUNTFLAG ) {

		// clear flag

		SysTick->CTRL &=~ CTRL_COUNTFLAG ;

		// do something

		systick_callback();

	}

}

/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of a Systick interrupt Driver
 * Usage:
 * User LED3 is toggled every 1s, trough Systick interrupt
 ******************************************************************************
 */

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

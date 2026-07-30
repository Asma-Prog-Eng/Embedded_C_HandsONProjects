/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal Timer Driver implementation
 * Toggle User LED6 at a configurable delay generated using Timer 2
 * The delay can be configured in Hz or in seconds
 *  Example :
 * Timer2_init(10, 's') toggle the led every 10 seconds
 *  Timer2_init(10, 'h') toggle the led at 10 hz (1/10 seconds)
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "Timer.h"

int main(void) {


	GPIOD_init();

	Timer2_init(2, 'h');

	while (1) {

		LED_Toggle();

	}


}

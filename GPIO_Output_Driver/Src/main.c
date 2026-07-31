/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of a GPIO Output Driver 
 * Toggle LED connected to PA5 at a PLL clock frequency of 50 Mz
 * 
 ******************************************************************************/

#include "GPIOA_Output.h"
#include "stm32f4xx.h"

int main (void) {


	 GPIOA_Init();


	while (1) {


		LED_toggle();

	}

	return  0;
}




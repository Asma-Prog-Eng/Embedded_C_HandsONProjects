/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of an Output Compare Timer Driver
 * PA5 is toggled through Timer2 set in output compare mode
 * Delay mode can be set in seconds or in frequency
 ******************************************************************************
 */

#include "stm32f4xx.h"

#include "Time.h"

int main(void){

	GPIOA_Init();

	Timer2_output_compare_init(5, 'h');


}

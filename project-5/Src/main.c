/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of a Systick Driver
 * TON/OFF delay implementation to toggle User LED3 : 
 * TON delay = 1s, TOFF delay = 2s
 ******************************************************************************
 */


#include "stm32f4xx.h"

#include "Systick.h"

#include <stdio.h>

int main(void){


	 Systick_init();

	 GPIOD_init();

	while(1) {

		LED_toggle();

	}

}

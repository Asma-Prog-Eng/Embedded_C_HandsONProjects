/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of a UART Driver
 * Transmit a character from RealTerm Terminal 
 * If received character = '1' then switch on LED at PB7
 * ELSE switch off LED and display the received character 
 * 
 ******************************************************************************/

#include <stdio.h>
#include "stm32f3xx.h"
#include <stdint.h>
#include <uart.h>

#define GPIOBEN     (1UL << 18)
#define LED_PIN     (1UL << 7)

char key = '\0';

int main() {


	UART2_init () ;

	 // Enable clock access for Port B
    RCC->AHBENR |= GPIOBEN;

    // set MODER bits for PB7 (bits 14 and 15) to output mode (01)
    GPIOB->MODER &= ~(1UL << 15);
    GPIOB->MODER |=  (1UL << 14);

	while (1) {


		key = uart2_read();


		if (key == '1') {

			GPIOB->ODR |= LED_PIN;   // Set PB7 high

	    }

		else {

			GPIOB->ODR &= ~LED_PIN;  // Set PB7 low
			uart2_write(key);        // display the entered character on terminal
		}
	}
}


/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of a UART Driver
 * Usage:
 * a character is entered in RealTerm Terminal
 * If it is = 1 , then User LED is switched on
 * Else LED is turned OFF
 * and the entered character is send back and displayed
 * on the serial terminal
 ******************************************************************************
 */

#include "stm32f4xx.h"

#include "UART.h"

#include <stdio.h>


int main(void) {

	char key = '\0';

	GPIO_Init();

	uart_init(USART1, 4800) ;


	while (1) {

		key = uart_read(USART1);

       if(key == '1') {

    	   GPIOD->ODR |= LED_ON;

       }

       else {

    	   GPIOD->ODR &= ~LED_ON;
    	   uart_write(USART1, key);
       }

	}


}

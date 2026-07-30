/*
 * main_app.c
 *  Using HSE as clock source to configure :
 *  SYSCLK as 8 Mhz
 *  APB1 as 2 MHZ
 *  APB2 as 2MHZ
 *  AHB as 4 MHZ and
 *  transmit this frequency values to the serial terminal using USART 2 (PA2 = tx, PA3 = rx)
 *  Baud rate = 115200
 *  Board  : Nucleo 64, STM32F103Rb
 *  Serial Terminal : Terra Term
 *  Created on: May 3, 2026
 *      Author: asmae
 */

void UART2_Init(void);
void Error_handler(void);
void Print_Freq(void);
void SYSCLK_Config(void);


#include "stm32f1xx_hal.h"
#include "msp.h"
#include "it.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// uart struct. declaration
UART_HandleTypeDef huart2;

// RCC OSC struct. declaration
RCC_OscInitTypeDef osc_init;

// CLK Config struct. declaration
RCC_ClkInitTypeDef clk_init;

// data buffer
char msg[100];

int main(void){


	// HAL library inits.
	HAL_Init();

	char *user_data = "\n\n*************** The application is running ***************\r\n\n";

	// SYSCLK configuration
	SYSCLK_Config();

	// uart inits.
	UART2_Init();

	// send user data to the serial terminal
	HAL_UART_Transmit(&huart2, (uint8_t*) user_data, (uint16_t) strlen(user_data), HAL_MAX_DELAY ) ;

	// display clk frequencies
	Print_Freq();

    // reset board to restart the program by runnin infinite loop
    while(1) {;}

    return 0 ;

}


void SYSCLK_Config(void) {

	// 1. Enable HSE SYSCLK and configure it as source clock

		memset(&osc_init, 0, sizeof(osc_init));

		osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;

		osc_init.HSEState = RCC_HSE_ON  ;

		if (HAL_RCC_OscConfig(&osc_init) != HAL_OK) {

			 // there is a problem
					 Error_handler();

		};

		// 2 . Configure AHB , APB1 AND APB2 Precsalers

		memset(&clk_init, 0, sizeof(clk_init));

		clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK \
							| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 ;

		clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE ;

		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2 ;

		clk_init.APB1CLKDivider = RCC_HCLK_DIV2 ;

		clk_init.APB2CLKDivider = RCC_HCLK_DIV2 ;

		HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0 );

		__HAL_RCC_HSI_DISABLE(); // save some current

		// Sysclk configuration

		HAL_SYSTICK_Config( HAL_RCC_GetSysClockFreq()/1000);

		HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

void Print_Freq(void) {

	    // display SYSCLK Feq.
		memset(msg, 0, sizeof(msg));
		sprintf(msg, "SYSCLK : %lu \r\n", HAL_RCC_GetSysClockFreq());
		HAL_UART_Transmit(&huart2, (uint8_t*) msg,  strlen(msg), HAL_MAX_DELAY);

		 // display HCLK Feq.
		memset(msg, 0, sizeof(msg));
		sprintf(msg, "HCLK   : %lu \r\n",  HAL_RCC_GetHCLKFreq());
		HAL_UART_Transmit(&huart2, (uint8_t*) msg,  strlen(msg), HAL_MAX_DELAY);

		 // display PCLK1 Feq.
		memset(msg, 0, sizeof(msg));
		sprintf(msg, "PCLK1  : %lu \r\n", HAL_RCC_GetPCLK1Freq());
		HAL_UART_Transmit(&huart2, (uint8_t*) msg,  strlen(msg), HAL_MAX_DELAY);

		 // display PCLK2 Feq.
		memset(msg, 0, sizeof(msg));
		sprintf(msg, "PCLK2  : %lu \r\n", HAL_RCC_GetPCLK2Freq());
		HAL_UART_Transmit(&huart2, (uint8_t*) msg,  strlen(msg), HAL_MAX_DELAY);

}

void UART2_Init(void)
{

	 huart2.Instance =  USART2;
	 huart2.Init.BaudRate = 115200;
	 huart2.Init.WordLength = UART_WORDLENGTH_8B ;
	 huart2.Init.StopBits = UART_STOPBITS_1;
	 huart2.Init.Parity = UART_PARITY_NONE ;
	 huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	 huart2.Init.Mode = UART_MODE_TX_RX  ;
	 HAL_UART_Init(&huart2);
	 if( HAL_UART_Init(&huart2)!= HAL_OK){

		 // there is a problem
		 Error_handler();

	 }
	 HAL_UART_MspInit(&huart2);
}

void Error_handler(void){

	// Infinite loop if error occurs, blinking a led can be used too here instead

	while(1);

}



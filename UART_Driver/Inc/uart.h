/*
 * uart.h
 *
 *  Created on: Jul 9, 2025
 *   Author: asmae
 */
#include "stm32f3xx.h"
#include <stdint.h>
#ifndef UART_H_
#define UART_H_

void UART2_init (void) ;

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate );

uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t Baudrate);

void uart2_write(int ch) ;

char uart2_read(void) ;


#endif /* UART_H_ */

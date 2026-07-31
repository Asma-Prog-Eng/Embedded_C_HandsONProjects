
#include <uart.h>

#define GPIOAEN        (1U << 17 )

#define UART2EN        (1U << 17)

#define CR1_TE         (1U << 3)

#define CR1_UE         (1U << 0)

#define SR_TXE          (1U << 7)

#define SYS_FREQ       8000000U

#define APB2_CLK       SYS_FREQ

#define UART_BAUDRATE  115200

#define CR1_RE         (1U << 2)

#define CR1_UE         (1U << 0)

#define SR_RXNE          (1U << 5)


void UART2_init (void) {


	/***************************************Configure uart gpio pin*********************************************************/

	/* Enable clock access to gpio port A */
	RCC->AHBENR |= GPIOAEN;

	/* Set PA2 as AF7*/
	GPIOA->MODER &= ~(1UL << 4);
	GPIOA->MODER  |= (1UL << 5);


	/*Set PA2  alternate function type to UART_TX (AF07)*/

	GPIOA->AFR[0] |= (1U << 8) ;
	GPIOA->AFR[0] |= (1U << 9) ;
	GPIOA->AFR[0] |= (1U << 10) ;
	GPIOA->AFR[0] &= ~(1U << 11);


	/* Set PA15 as AF7*/
	GPIOA->MODER &= ~(1UL << 30);
	GPIOA->MODER  |= (1UL << 31);

	/*Set PA15  alternate function type to UART_TX (AF07)*/

	GPIOA->AFR[1] |= (1U << 28) ;
	GPIOA->AFR[1] |= (1U << 29) ;
	GPIOA->AFR[1] |= (1U << 30) ;
	GPIOA->AFR[1] &= ~(1U << 31);

	/***************************************Configure uart module **********************************************************/

	/* Enable clock access to uart1 */
	RCC->APB1ENR |= UART2EN;

	/* Configure baudrate */
    uart_set_baudrate(USART2,APB2_CLK , UART_BAUDRATE );

	/* Configure the transfer direction*/
	USART2->CR1 = (CR1_TE | CR1_RE );



	/* Enable UART transmitter module */
	USART2->CR1 |= CR1_UE;

}



void uart2_write(int ch) {

	/* Wait until transmit buffer empty */

	while (!(USART2->ISR & SR_TXE)){}


	/* Write to transmit data register */

	// & operation because we want to transmit 8 bits
	USART2->TDR = (ch & 0xFF) ;

}


char uart2_read(void) {

	/* Wait until read buffer is not empty */

	while (!(USART2->ISR & SR_RXNE)){}

	/* read data register */

	return (USART2->RDR & 0xFF);

}


void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate ){

	USARTx->BRR = compute_uart_BD( PeriphClk, Baudrate);


}

uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t Baudrate){

	return ( (PeriphClk + (Baudrate/2U)) /Baudrate);


}






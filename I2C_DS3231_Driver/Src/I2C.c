#include "stm32f4xx.h"

#include "I2C.h"

#define AF4_1      				(1U << 26)

#define AF4_2      				(1U << 30)

#define GPIOBEN    				(1U << 1)

#define GPIODEN    				(1U << 3)

#define GPIOB_MODER_1			(1U << 13)

#define GPIOB_MODER_2			(1U << 12)

#define GPIOB_MODER_3			(1U << 15)

#define GPIOB_MODER_4			(1U << 14)


#define GPIOB_MODER_5			(1U << 10)

#define GPIOB_MODER_6			(1U << 11)


#define GPIOD_MODER_1			(1U << 24)

#define GPIOD_MODER_2		    (1U << 25)

#define I2C1EN                  (1U << 21)

#define CR1_PE                  (1U << 0)

#define CR1_START               (1U << 8)

#define CR1_STOP                (1U << 9)

#define CR2_FREQ                (1U << 4)

#define SR1_TxE                 (1U << 7)

#define SR1_ADDR                (1U << 1)

#define CCR_F_S                 (1U << 0)

#define CCR_CCR                 ((1U << 3) | (1U << 5))

#define CR1_ACK                 (1U << 10)

#define SR1_RxNE                 (1U << 6)

#define I2C_100KHZ               80

#define SD_MODE_MAX_RISE_TIME    17

#define SR2_Busy                (1U << 1)

#define SR1_SB                  (1U << 0)

#define SR1_TxE                 (1U << 7)

#define SR1_RxE                 (1U << 6)

#define SR1_BTF                 (1U <<2)


void I2C_init(void) {


	// enable clock access to I2C1

    RCC->APB1ENR |= I2C1EN ;

    //Set I2C under reset

    I2C1->CR1 |= (1U << 15);

    // Come out of the reset

    I2C1->CR1 &= ~(1U << 15);

    // define Sm mod

    I2C1->CCR |= CCR_F_S;

    // select input peripheral clock to  16Mhz(I2C_CR2),

      I2C1->CR2 = CR2_FREQ  ;

    // configure clock frequency to 100 KHz

     I2C1->CCR = I2C_100KHZ;


     // maximum Rise time  to 17 to obtain 100KHZ

     I2C1->TRISE = SD_MODE_MAX_RISE_TIME  ;

 // Enable I2C peripheral in I2C_CR1


    I2C1->CR1|= CR1_PE  ;


}


void GPIO_I2C_init(void){


// enable clock access to port B and D

	RCC->AHB1ENR |= (GPIOBEN | GPIODEN)  ;

// set pin PB6 and PB7 to  open drain

	GPIOB->OTYPER |= (1U << 6);

	GPIOB->OTYPER |= (1U << 7);

// Enable pull-up for PB6 and PB7

	GPIOB->PUPDR |= ((1U << 12) |(1U << 14));

// enable alternate mode for SCL pin : PB6

	GPIOB->MODER |= GPIOB_MODER_1;

	GPIOB->MODER &= ~GPIOB_MODER_2;

// enable alternate mode for SDA pin: PB7

	GPIOB->MODER |= GPIOB_MODER_3;

	GPIOB->MODER &= ~GPIOB_MODER_4;

// set AFRL to AF4 for pin SCL pin : PB6

   GPIOB->AFR[0] &= ~(1U << 24) ;

   GPIOB->AFR[0] &= ~(1U << 25) ;

   GPIOB->AFR[0] |= (1U << 26) ;

   GPIOB->AFR[0] &= ~(1U << 27) ;

// set AFRL/H to AF4 for pin SDA pin : PB7

   GPIOB->AFR[0] &= ~(1U << 28) ;

   GPIOB->AFR[0] &= ~(1U << 29) ;

   GPIOB->AFR[0] |= (1U << 30) ;

   GPIOB->AFR[0] &= ~(1U << 31) ;

   // PD12 as output

   GPIOD->MODER |= GPIOD_MODER_1;

   GPIOD->MODER &= ~GPIOD_MODER_2;



}


void read_Byte(char saddr, char maddr, char* data){

    volatile int tmp = 0  ;

	// wait till bus is not busy

	while(I2C1->SR2 & SR2_Busy );

	// Generate start condition

	I2C1->CR1 |= CR1_START;

	// wait till start flag is set

	while(!(I2C1->SR1 & SR1_SB ));

	// transmit slave address + write

	I2C1->DR = saddr << 1 ;

	// wait till addr flag is set

	while (!(I2C1->SR1 & SR1_ADDR)){};


	// clear addr flag

	tmp = I2C1->SR2;


	// wait till transmitter empty

	while (!(I2C1->SR1 & SR1_TxE)){};

	// send memory address

	I2C1->DR = maddr;

	// wait till transmitter empty

	while (!(I2C1->SR1 & SR1_TxE)){};

	// Generate restart condition

	I2C1->CR1 |= CR1_START;


	// wait till start flag is set

	while (!(I2C1->SR1 & SR1_SB)) {};

	// transmit slave address + Read

	I2C1->DR = saddr << 1 | 1 ;

	while (!(I2C1->SR1 & SR1_ADDR)){};

	// disable ACK

	I2C1->CR1 &= ~CR1_ACK ;

	// clear addr flag

	tmp = I2C1->SR2;


	//Generate stop condition

	I2C1->CR1 |= CR1_STOP;

	// wait till data register is not empty

	while (!(I2C1->SR1 & SR1_RxE)){};

	// return data
	*data++ = I2C1->DR ;


}





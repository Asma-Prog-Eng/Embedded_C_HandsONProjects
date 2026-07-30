
/**
 **********************************************************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 *********************************************************************************************************************
 * Bare metal implementation of an I2C driver that interface with DS3231 Real Time Clock RTC real -time (RTC)
 * to toggle a LED every second
 *********************************************************************************************************************/

#include "stm32f4xx.h"
#include "I2C.h"

char data;


int main(void)
{

	 GPIO_I2C_init();

	 I2C_init();

   while(1) {


       read_Byte( DS323_ADDR, 0x00, &data);

	   if( data & 1){

		   GPIOD->ODR ^= (1U <<12);

	   }

   }

}




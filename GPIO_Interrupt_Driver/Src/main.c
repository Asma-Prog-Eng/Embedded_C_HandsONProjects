
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal Implementation of a GPIO Interrupt Driver 
 * If button B1 is pressed, an interrupt is generated
 * to toggle LD4
 ******************************************************************************
 */


#include "stm32f4xx.h"

#include "GPIO_Interrupt.h"

static void exti_callback(void);



int main(void) {

	 GPIO_Init() ;

	 exti_0_Init();

	while (1) {

	}
}


static void exti_callback(void) {

	// toggle LED PD12

	GPIOD->ODR ^= LED_ON;

}



void EXTI0_IRQHandler(void){

	// check if interrupt occured

	if( (EXTI->PR & LINE0) !=0) {

		// clear PR flag

		EXTI->PR |= LINE0;
       // Do something

		exti_callback();


	}

}




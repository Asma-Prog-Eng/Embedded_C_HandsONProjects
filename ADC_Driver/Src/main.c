/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal ADC Interrupt Driver implementation
 * Each time measurement is done, an interrupt is generated
 * and the measured potentiometer voltage is displayed , on debugging mode
 ******************************************************************************
 **/

#include "stm32f4xx.h"
#include "ADC.h"



static void adc_callback(void);

// declared as global for debugging purposes

double Pot_Voltage = 0.0;

int main (void) {

	GPIO_init();
	ADC1_Init();

	start_conversion();

	while (1) {


	}

	return  0;
}


// static so that it can be only accessed here

static void adc_callback(void) {


	uint16_t Raw_val = 0;

	// input reference voltage

	double Vref = 3.00;


	// 8-bit ADC converter
	double ADC_resolution  = 256.0;

   // display the received value , used for debugging

   Raw_val =  (ADC1->DR & 0xFF) ;

   Pot_Voltage = (Raw_val *Vref)/(ADC_resolution-1);


}


void ADC_IRQHandler(void) {


	//check for end of conversion in SR register , if EOC is set

	if ((ADC1->SR & SR_EOC)) {

		ADC1->SR &=~ SR_EOC;

		adc_callback();

	}

}





#include "stm32f4xx.h"
#include "Systick.h"


#define CTRL_CLKSOURCE       (1U << 2)

#define CTRL_ENABLE          (1U << 0)

#define CTRL_COUNTFLAG            (1U << 16)

#define RCC_GPIOD_EN              (1U <<3)

#define GPIOD_MODER_1             (1U << 26)

#define GPIOD_MODER_2             (1U << 27)

#define LED_PIN                    13

#define SysClock                   8000000UL

#define CTRL_TICKINT               (1U << 1)

void Systick_interrupt_init(void){

	  // disable global interrupts

	    __disable_irq();

	// enable clock source process clock

	    SysTick->CTRL |= CTRL_CLKSOURCE;

	// enable systick interrupt request

	    SysTick->CTRL |= CTRL_TICKINT ;

	// Enable Systick interrupt  in NVIC

	    NVIC_EnableIRQ(SysTick_IRQn);

	// enable global interrtupts

	    __enable_irq();


}

// will be updated soon for varied value of delays

void Delay_1s_configuration(int Delay_s){

	// write value to load register N = Freq_Hz * SysClock , SysClock = 16Mhz

	int  N = Delay_s * SysClock;

	SysTick->LOAD |= (N -1);

	// Clear sytick current value register

	SysTick->VAL = 0;

	// enable counter

	SysTick->CTRL |= CTRL_ENABLE;


}


void GPIOD_init(void) {

	// enable clock access to port D

	RCC->AHB1ENR |= RCC_GPIOD_EN ;

	// set PD13 mode to output

   GPIOD->MODER |=  GPIOD_MODER_1 ;

   GPIOD->MODER &=  ~GPIOD_MODER_2 ;

}





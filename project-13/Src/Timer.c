
#include "stm32f4xx.h"
#include "Timer.h"


#define CR1_CEN   (1U << 0)

#define CR1_DIR   (1U << 4)

#define SR_UIF    (1U << 0)

#define RCC_GPIOD_EN              (1U <<3)

#define GPIOD_MODER_1             (1U << 30)

#define GPIOD_MODER_2             (1U << 31)

#define LED_PIN                    15

#define TIM2EN                    (1U << 0)

#define SysCLCK                   16000000UL

void Timer2_init(int Prescaler, char SecOrFreq) {

	uint32_t Preload_VAL = 0, Timer_Prescaler = 0;

	Timer_Prescaler = 1600;

	// Enable clock acess to timer 2

	RCC->APB1ENR |= TIM2EN  ;

    // set Timer prescaler to 2


	 TIM2->PSC =  Timer_Prescaler -1 ;

	// Enable Upcounting mode :  CR1_DIR

	 TIM2->CR1 |= CR1_DIR;

	// read the preload value

	 if (SecOrFreq == 'h' ) {

		 Preload_VAL =  ( SysCLCK/Timer_Prescaler)/ Prescaler  ;

	 }

	 if (SecOrFreq == 's' ) {

			 Preload_VAL =  Prescaler * ( SysCLCK/Timer_Prescaler)  ;

		 }

	 TIM2->ARR = Preload_VAL - 1;

     // clear counter

	 TIM2->CNT = 0;

	// Enable counter TIMx_CR1 : CEN bit

    TIM2->CR1 |= CR1_CEN ;

}

void Start_Timer2(void){

	// clear flags

	TIM2->SR &= ~1;

	// wait till counting is done

	while(!(TIM2->SR & SR_UIF)) {};



}

void GPIOD_init(void){

	// enable clock access to port D

	RCC->AHB1ENR |= RCC_GPIOD_EN ;

	// set PD15 mode to output

   GPIOD->MODER |=  GPIOD_MODER_1 ;

   GPIOD->MODER &=  ~GPIOD_MODER_2 ;

}

void LED_Toggle (void){


	// start Timer 2

	 Start_Timer2() ;

	 // toggle LED PD15

	GPIOD->ODR ^= (1U << LED_PIN );




}

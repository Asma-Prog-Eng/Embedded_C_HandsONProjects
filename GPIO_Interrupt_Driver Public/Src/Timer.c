

#include "stm32f4xx.h"

#include "Time.h"

#define CR1_CEN   				  (1U << 0)

#define CR1_DIR   				  (1U << 4)

#define SR_UIF    				  (1U << 0)

#define RCC_GPIOA_EN              (1U << 0)

#define GPIOA_MODER_1             (1U << 10)

#define GPIOA_MODER_2             (1U << 11)

#define TIM2EN                    (1U << 0)

#define SysCLCK                   16000000UL

#define OC_TOGGLE                 ((1U << 4) | (1U << 5))

#define CCMR1_OC1PE                (1U << 3)

#define CCER_CC1P                 (1U << 1)

#define CCER_CC1E                 (1U << 0)

#define TIM2_AF1				  (1U << 20)

void Timer2_output_compare_init(int Prescaler, char SecOrFreq) {


	uint32_t Preload_VAL = 0, Timer_Prescaler = 0;

	// enable clock access to port A

	RCC->AHB1ENR |= RCC_GPIOA_EN ;

	// set PA5 mode to output

	GPIOA->MODER &=  ~GPIOA_MODER_1 ;

    GPIOA->MODER |=  GPIOA_MODER_2 ;

    // set alternate function to AF1

    GPIOA->AFR[0] |= TIM2_AF1;


	Timer_Prescaler = 1600;

	// Enable clock acess to timer 2

	RCC->APB1ENR |= TIM2EN  ;

	// set Timer prescaler to 2


	TIM2->PSC =  Timer_Prescaler -1 ;

	// Enable Upcounting mode :

	TIM2->CR1 |= CR1_DIR;

	// read the preload value

	if (SecOrFreq == 'h' ) {

		Preload_VAL =  ( SysCLCK/Timer_Prescaler)/ Prescaler  ;

	}

	if (SecOrFreq == 's' ) {

		Preload_VAL =  Prescaler * ( SysCLCK/Timer_Prescaler)  ;

	}

	TIM2->ARR = Preload_VAL - 1;

	// Select the output mode

	TIM2->CCMR1 |= 	 OC_TOGGLE ;

	TIM2->CCMR1 &=~CCMR1_OC1PE ;

	TIM2->CCER &=~CCER_CC1P ;

	TIM2->CCER |= CCER_CC1E;

	TIM2->CNT = 0;

	// Enable counter TIMx_CR1 : CEN bit

	 TIM2->CR1 |= CR1_CEN ;

}


void GPIOA_Init(void){

	// enable clock access to port A

	RCC->AHB1ENR |= RCC_GPIOA_EN ;

	// set PA5 mode to output

	GPIOA->MODER &=  ~GPIOA_MODER_1 ;

    GPIOA->MODER |=  GPIOA_MODER_2 ;

    // set alternate function to AF1

    GPIOA->AFR[0] |= TIM2_AF1;

}



#ifndef GPIO_INTERRUPT_H_
#define GPIO_INTERRUPT_H_

#include "stm32f4xx.h"


#define LINE0     		(1U << 0)

#define LED_ON    		(1U << 12)


void GPIO_Init(void);

void exti_0_Init(void);

#endif /* GPIO_INTERRUPT_H_ */

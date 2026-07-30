/*
 * ADC.h
 *
 *  Created on: Jul 14, 2025
 *      Author: asmae
 */

#ifndef ADC_H_
#define ADC_H_

#define SR_EOC          (1U << 1)

#define LED_ON    		(1U << 12)

void ADC1_Init(void);

void GPIO_init(void);

void start_conversion(void);


#endif /* ADC_H_ */

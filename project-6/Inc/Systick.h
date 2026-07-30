/*
 *
 *
 *
 *
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void Systick_interrupt_init(void);

void Delay_1s_configuration(int Delay_s);

void GPIOD_init(void);

#define LED_PIN                    13

#define CTRL_COUNTFLAG             (1U << 16)

#endif /* SYSTICK_H_ */

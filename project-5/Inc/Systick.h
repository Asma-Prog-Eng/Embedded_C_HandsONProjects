/*
 *
 *
 *
 *
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void Systick_init(void);

void Delay_configuration(int delay_s);

void GPIOD_init(void);

void LED_toggle(void);

#endif /* SYSTICK_H_ */

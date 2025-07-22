#ifndef TIMER_H_
#define TIMER_H_

void Timer2_init(int Prescaler, char SecOrFreq);

void Start_Timer2(void);
void GPIOD_init(void);
void LED_Toggle (void);

#endif /* TIMER_H_ */

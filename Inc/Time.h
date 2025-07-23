
#ifndef TIMER_H_
#define TIMER_H_

void Timer2_output_compare_init(int Prescaler, char SecOrFreq);

void GPIOA_Init(void);

void Timer3_input_capture_init(void);

#endif /* TIMER_H_ */

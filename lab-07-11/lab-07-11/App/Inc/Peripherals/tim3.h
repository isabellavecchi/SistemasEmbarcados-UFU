/*
 * timer.h
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#ifndef INC_PERIPHERALS_TIM3_H_
#define INC_PERIPHERALS_TIM3_H_

#include "hw_Timer.h"

extern TIM_HandleTypeDef htim3;

void StartTimer();
void setTim3CallbackFn(void (*timCallbackFunc)(void));
void timOscilateARR();

//void hw_register_timer_callback(void (*callback)(void)); //para trocar o estado do led

#endif /* INC_PERIPHERALS_TIM3_H_ */

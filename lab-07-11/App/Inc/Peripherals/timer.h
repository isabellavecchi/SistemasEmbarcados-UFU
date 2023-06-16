/*
 * timer.h
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#ifndef INC_PERIPHERALS_TIMER_H_
#define INC_PERIPHERALS_TIMER_H_

#include "hw_Timer.h"

void deboucingTimeCapsule(void (*function)(void));
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void setCallbackFn(void (*callback)(void));

//void hw_set_timer_period(uint16_t period);
//void hw_register_timer_callback(void (*callback)(void)); //para trocar o estado do led

#endif /* INC_PERIPHERALS_TIMER_H_ */

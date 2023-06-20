/*
 * hw_Timer.h
 *
 *  Created on: May 15, 2023
 *      Author: isabe
 */

#ifndef INC_HARDWARE_TIMER_H_
#define INC_HARDWARE_TIMER_H_

#include <stdint.h>
#include "main.h"

#define DEBOUNCING_TIME 64

void hw_delay_ms(uint32_t time_ms);
uint32_t hw_getInstant(void);
void hw_cpuSleep(void);

void deboucingTimeCapsule(void (*function)(void));

void hw_timBaseStartIT(TIM_HandleTypeDef *htim);
void hw_timBaseStopIT(TIM_HandleTypeDef *htim);
void hw_setTimAutoReload(TIM_HandleTypeDef *htim, uint16_t timeValue);
void hw_ressetTimCounter(TIM_HandleTypeDef *htim);
//	funcao para pausar o periferico que vier na frente do freeze
//	__HAL_DBGMCU_FREEZE_TIM3();


#endif /* INC_HARDWARE_TIMER_H_ */

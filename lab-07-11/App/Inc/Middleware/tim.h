/*
 * tim.h
 *
 *  Created on: Jun 20, 2023
 *      Author: isabe
 */

#ifndef INC_MIDDLEWARE_TIM_H_
#define INC_MIDDLEWARE_TIM_H_

#include "hw_Timer.h"

extern TIM_HandleTypeDef htim3;

void mw_startTimer(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void mw_setTim3CallbackFn(void (*callback)(void));

#endif /* INC_MIDDLEWARE_TIM_H_ */

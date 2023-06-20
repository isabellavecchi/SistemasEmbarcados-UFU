/*
 * hw_Timer.c
 *
 *  Created on: May 15, 2023
 *      Author: isabe
 */

#include <hw_Timer.h>

void hw_delay_ms(uint32_t time_ms){
	HAL_Delay(time_ms);
}

uint32_t hw_getInstant(void) {
	return HAL_GetTick();
}

void hw_cpuSleep(void) {
//	__WFI();
}

void deboucingTimeCapsule(void (*function)(void)) {
	static uint32_t instant = 0;
	if (hw_getInstant() - instant >= DEBOUNCING_TIME) {
		instant = hw_getInstant();
		function();
	}
}

void hw_timBaseStartIT(TIM_HandleTypeDef *htim) {
	HAL_TIM_Base_Start_IT(htim);
}

void hw_timBaseStopIT(TIM_HandleTypeDef *htim) {
	HAL_TIM_Base_Stop_IT(htim);
}

void hw_setTimAutoReload(TIM_HandleTypeDef *htim, uint16_t timeValue) {
	__HAL_TIM_SET_AUTORELOAD(htim, timeValue);
}

void hw_ressetTimCounter(TIM_HandleTypeDef *htim) {
	__HAL_TIM_SET_COUNTER(htim, 0);
}

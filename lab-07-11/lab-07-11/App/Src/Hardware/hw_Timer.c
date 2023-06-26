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

void hw_ressetTimCounter(TIM_HandleTypeDef *htim) {
	__HAL_TIM_SET_COUNTER(htim, 0);
}

void hw_setTimAutoReload(TIM_HandleTypeDef *htim, uint16_t timeValue) {
	__HAL_TIM_SET_AUTORELOAD(htim, timeValue);
}




void hw_deboucingTimeCapsule(void (*function)(void)) {
	static uint32_t instant = 0;
	if (hw_getInstant() - instant >= DEBOUNCING_TIME) {
		instant = hw_getInstant();
		function();
	}
}



void hw_startTimer(TIM_HandleTypeDef *htim, uint32_t newARR) {
	__HAL_TIM_SET_AUTORELOAD(htim, newARR);
	hw_ressetTimCounter(htim);
	HAL_TIM_Base_Start_IT(htim);
}

void (*usr_swt_cbk_htim3)(void) = NULL;

void hw_oscilatesFunctionForNLoops(void (*function)(void), uint32_t nLoops) {
	// depois de 4 ciclos de repeticoes, desliga o tim3_IT
	static uint32_t cnt = 0;

	function();

	if(++cnt >= nLoops) {
		// desliga aqui
		HAL_TIM_Base_Stop_IT(&htim3);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim == &htim3) {
		if (usr_swt_cbk_htim3 != NULL) {
			hw_oscilatesFunctionForNLoops(usr_swt_cbk_htim3, 4);
		}
	}
}

void hw_setTim3CallbackFn(void (*callback)(void)) {
	usr_swt_cbk_htim3 = callback;
}

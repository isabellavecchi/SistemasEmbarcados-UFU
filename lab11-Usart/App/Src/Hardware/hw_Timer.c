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

uint32_t getInstant(void) {
	return HAL_GetTick();
}

void hw_cpu_sleep(void) {
//	__WFI();
}

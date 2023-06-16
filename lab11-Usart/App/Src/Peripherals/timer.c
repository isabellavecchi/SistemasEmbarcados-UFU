/*
 * timer.c
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#include "timer.h"

void (*usr_swt_cbk)(void) = NULL;

void deboucingTimeCapsule(void (*function)(void)) {
	static uint32_t instant = 0;
	if (getInstant() - instant >= DEBOUNCING_TIME) {
		instant = getInstant();
		function();
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (usr_swt_cbk != NULL) {
		deboucingTimeCapsule(usr_swt_cbk);
//		static uint32_t instant = 0;
//		if (getInstant() - instant >= DEBOUNCING_TIME) {
//			instant = getInstant();
//			usr_swt_cbk();
//		}
	}
}

void setCallbackFn(void (*callback)(void)) {
	usr_swt_cbk = callback;
}

// ck_cntt ck_psc autoreloadregister
// para debouncing
//HAL_GPIO_EXT1_CALLBACK
// extern para virar variavel global entre arquivos
//HAL_TIM_Per


// HAL_IncTick -> sobrescrever o delay da piscada para piscar o led
// a vari[avel ja andou tantos milissegundos? entao chamo minha funcao de callback


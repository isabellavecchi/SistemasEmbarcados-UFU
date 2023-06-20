/*
 * tim3.c
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#include <tim3.h>

void StartTimer() {
	mw_startTimer(&htim3);
}

void setTim3CallbackFn(void (*callback)(void)) {
	mw_setTim3CallbackFn(callback);
}



// ck_cntt ck_psc autoreloadregister
// para debouncing
//HAL_GPIO_EXT1_CALLBACK
// extern para virar variavel global entre arquivos
//HAL_TIM_Per


// HAL_IncTick -> sobrescrever o delay da piscada para piscar o led
// a vari[avel ja andou tantos milissegundos? entao chamo minha funcao de callback


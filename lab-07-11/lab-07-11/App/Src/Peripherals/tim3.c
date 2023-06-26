/*
 * tim3.c
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#include <tim3.h>



static uint32_t pos = 0;
uint32_t timValues[] = {199, 399, 199, 3199};

void StartTimer() {
	pos = 0;
	hw_startTimer(&htim3, timValues[pos]);
}

//void (*timCallbackFunc)(void) = NULL;

void setTim3CallbackFn(void (*timCallbackFunc)(void)) {
	// faz o periodo do clock variar
	if (timCallbackFunc != NULL) {
		hw_setTim3CallbackFn(timCallbackFunc);
	}
}

void timOscilateARR() {
	if (pos >= 4)
		pos = 0;
	hw_setTimAutoReload(&htim3, timValues[pos]);
	hw_ressetTimCounter(&htim3);
	pos++;
}



// ck_cntt ck_psc autoreloadregister
// para debouncing
//HAL_GPIO_EXT1_CALLBACK
// extern para virar variavel global entre arquivos
//HAL_TIM_Per


// HAL_IncTick -> sobrescrever o delay da piscada para piscar o led
// a vari[avel ja andou tantos milissegundos? entao chamo minha funcao de callback


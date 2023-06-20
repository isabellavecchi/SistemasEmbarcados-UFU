/*
 * tim.c
 *
 *  Created on: Jun 20, 2023
 *      Author: isabe
 */

#include "tim.h"

uint32_t pos;
uint32_t timValues[] = {199, 399, 199, 3199};

void mw_startTimer(TIM_HandleTypeDef *htim) {
	pos = 0;
	hw_setTimAutoReload(htim, timValues[pos]);
	hw_ressetTimCounter(htim);
	hw_timBaseStartIT(htim);
}

void (*usr_swt_cbk_htim3)(void) = NULL;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	static uint32_t cnt = 0;
	if(htim == &htim3) {
		if (usr_swt_cbk_htim3 != NULL) {

			// faz o periodo do clock variar
			pos++;
			if (pos >= 4) {
				pos = 0;

				if(++cnt >= 4) {
					// depois de 4 ciclos de repeticoes, desliga o tim3_IT
					hw_timBaseStopIT(&htim3);
				}
			}

			hw_setTimAutoReload(&htim3, timValues[pos]);
			hw_ressetTimCounter(&htim3);

			usr_swt_cbk_htim3();
		}
	}
}

void mw_setTim3CallbackFn(void (*callback)(void)) {
	usr_swt_cbk_htim3 = callback;
}

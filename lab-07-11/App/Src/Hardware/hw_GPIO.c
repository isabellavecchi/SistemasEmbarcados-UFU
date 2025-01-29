/*
 * hw_GPIO.c
 *
 *  Created on: May 16, 2023
 *      Author: Isabella Vecchi Ferreira
 */

#include <hw_GPIO.h>

void (*usr_swt_cbk_gpio)(void) = NULL;

void hw_pinToggle(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_TogglePin(port, pin);
}

void hw_enablePin(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void hw_disablePin(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

bool hw_getPinState(GPIO_TypeDef* port, uint16_t pin) {
	return !(HAL_GPIO_ReadPin(port, pin));
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (usr_swt_cbk_gpio != NULL) {
		hw_deboucingTimeCapsule(usr_swt_cbk_gpio);
//		static uint32_t instant = 0;
//		if (getInstant() - instant >= DEBOUNCING_TIME) {
//			instant = getInstant();
//			usr_swt_cbk();
//		}
	}
}

void hw_setGPIOCallbackFn(void (*callback)(void)) {
	usr_swt_cbk_gpio = callback;
}

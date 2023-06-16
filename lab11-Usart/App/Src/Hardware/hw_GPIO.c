/*
 * hw_GPIO.c
 *
 *  Created on: May 16, 2023
 *      Author: Isabella Vecchi Ferreira
 */

#include <hw_GPIO.h>

void hw_pin_toggle(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_TogglePin(port, pin);
}

void hw_enable_pin(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void hw_disable_pin(GPIO_TypeDef* port, uint16_t pin) {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

bool hw_get_pin_state(GPIO_TypeDef* port, uint16_t pin) {
	return !(HAL_GPIO_ReadPin(port, pin));
}

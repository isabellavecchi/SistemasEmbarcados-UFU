/*
 * led.c
 *
 *  Created on: 16 de mai de 2023
 *      Author: Isabella Vecchi Ferreira
 */

#include "led.h"

#define ledPort USER_LED_GPIO_Port
#define ledPin	USER_LED_Pin

void ledToggle(void) {
	hw_pin_toggle(ledPort, ledPin);
}

void ledEnable(void) {
	hw_disable_pin(ledPort, ledPin);
}
void LedDisable(void) {
	hw_enable_pin(ledPort, ledPin);
}

bool getLedState(void) {
	return hw_get_pin_state(ledPort, ledPin);
}

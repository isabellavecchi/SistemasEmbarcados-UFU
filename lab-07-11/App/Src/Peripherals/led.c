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
	hw_pinToggle(ledPort, ledPin);
}

void ledEnable(void) {
	hw_disablePin(ledPort, ledPin);
}
void LedDisable(void) {
	hw_enablePin(ledPort, ledPin);
}

bool getLedState(void) {
	return hw_getPinState(ledPort, ledPin);
}

void setLEDCallbackFn(void (*callback)(void)) {
	hw_setGPIOCallbackFn(*callback);
}

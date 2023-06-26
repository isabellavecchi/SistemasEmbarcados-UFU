/*
 * hw_GPIO.h
 *
 *  Created on: May 16, 2023
 *      Author: isabe
 */

#ifndef INC_HARDWARE_GPIO_H_
#define INC_HARDWARE_GPIO_H_

#include <stdbool.h>
#include "hw_Timer.h"
#include "main.h"


void hw_pinToggle(GPIO_TypeDef* port, uint16_t pin);
void hw_enablePin(GPIO_TypeDef* port, uint16_t pin);
void hw_disablePin(GPIO_TypeDef* port, uint16_t pin);
bool hw_getPinState(GPIO_TypeDef* port, uint16_t pin);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void hw_setGPIOCallbackFn(void (*callback)(void));


#endif /* INC_HARDWARE_GPIO_H_ */

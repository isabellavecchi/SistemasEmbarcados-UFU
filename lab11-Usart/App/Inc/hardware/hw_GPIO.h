/*
 * hw_GPIO.h
 *
 *  Created on: May 16, 2023
 *      Author: isabe
 */

#ifndef INC_HARDWARE_GPIO_H_
#define INC_HARDWARE_GPIO_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"


void hw_pin_toggle(GPIO_TypeDef* port, uint16_t pin);
void hw_enable_pin(GPIO_TypeDef* port, uint16_t pin);
void hw_disable_pin(GPIO_TypeDef* port, uint16_t pin);
bool hw_get_pin_state(GPIO_TypeDef* port, uint16_t pin);


#endif /* INC_HARDWARE_GPIO_H_ */

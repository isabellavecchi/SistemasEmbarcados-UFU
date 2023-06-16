/*
 * hw_Timer.h
 *
 *  Created on: May 15, 2023
 *      Author: isabe
 */

#ifndef INC_HARDWARE_TIMER_H_
#define INC_HARDWARE_TIMER_H_

#include <stdint.h>
#include "main.h"

void hw_delay_ms(uint32_t time_ms);
uint32_t getInstant(void);
void hw_cpu_sleep(void);

#define DEBOUNCING_TIME 64


#endif /* INC_HARDWARE_TIMER_H_ */

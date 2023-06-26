/*
 * app.h
 *
 *  Created on: 14 de mai de 2023
 *      Author: isabe
 */

#ifndef INC_BLINKAPP_APP_H_
#define INC_BLINKAPP_APP_H_

#include "led.h"
#include "tim3.h"#include "hw_usart.h"


void ToggleLED (int time_ms);
void appInit (void);
void appLoop(void);
void appSwitchInterrupt(void);
void uart_data_received(void);

#endif /* SRC_BLINKAPP_APP_H_ */

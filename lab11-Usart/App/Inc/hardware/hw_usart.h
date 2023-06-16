/*
 * hw_usart.h
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */

#ifndef INC_HARDWARE_HW_USART_H_
#define INC_HARDWARE_HW_USART_H_

#include "main.h"

int hw_uart_tx(unsigned char *data,
				unsigned int len,
				unsigned int timeout);

int hw_uart_rx(unsigned char *data,
				unsigned int len,
				unsigned int timeout);

void setUartCallbackFn(void (*callback)(void));

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* INC_HARDWARE_HW_USART_H_ */

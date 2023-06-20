/*
 * hw_usart.c
 *
 *  Created on: Jun 6, 2023
 *      Author: isabe
 */
#include "hw_usart.h"

void (*usr_swt_uart_cbk)(void) = NULL;

int hw_uart_tx(unsigned char *data,
				unsigned int len,
				unsigned int timeout) {
	HAL_UART_Transmit_IT(&huart1, data, len);
	return len;
}

int hw_uart_rx(unsigned char *data,
				unsigned int len,
				unsigned int timeout) {
	HAL_UART_Receive_IT(&huart1, data, len);
	return len;
}

void hw_setUartCallbackFn(void (*callback)(void)) {
	usr_swt_uart_cbk = callback;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	usr_swt_uart_cbk();
}

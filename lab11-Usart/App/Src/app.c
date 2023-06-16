/*
 * app.c
 *
 *  Created on: 14 de mai de 2023
 *      Author: Isabella Vecchi Ferreira
  ******************************************************************************
  * @file           : app.c
  * @brief          : Main program body
  ******************************************************************************
  * Projeto Criado Para a Discilpina Sistemas Embarcados da UFU
  * Professores: Daniel Pereira de Carvalho e Marcelo Barros
  ******************************************************************************
  *
  * Funcionalidade: Piscar o Led (PC13) da Placa BlackPill da STM32F411CEU6 ao apertar
  * o botao conectado ao periferico PA0.
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "app.h"

//volatile uint32_t led_time_ms = 128;	//para definir variaveis que podem estar sempre mudando
bool hasAppStarted = false;

void appInit(void) {
	setCallbackFn(&appSwitchInterrupt);
	setUartCallbackFn(&uart_data_received);
	hasAppStarted = true;
}

void appLoop(void){
//	ToggleLED(300);
	hw_cpu_sleep();
}

void ToggleLED (int time_ms) {
	static uint32_t pressStart = 0;
	pressStart = getInstant();
	if (getInstant() - pressStart < time_ms) {
		ledToggle();
	}
}

unsigned char tx_data[] = "Hello World\n\r";


void appSwitchInterrupt(void) {

	if (!hasAppStarted) {
		return;
	}
}


void uart_data_received(void) {
	//echoa o que receber
	hw_uart_tx(tx_data, 13, 300);
	hw_uart_rx(tx_data, 13, 300);
}

//void setVoidLoopFn(void (*function)(void)) {
//	usr_loop_fn = function;
//}
//
//void setVoidSetupFn(void (*function)(void)) {
//	usr_setup_fn = function;
//}


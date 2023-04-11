#include <stdlib.h>
#include <stdint.h>
// #include "config.h"

// RCC: reset and clock control, ajusta a frequencia/periodo de execucao do meu compilador

static const char     fw_version[] = {'V', '1', '.', '0'};
static uint32_t led_status;
uint32_t *pGPIOC_BSRR, GPIO_BSRR13_SET, GPIO_BSRR13_RESET, LED_DELAY;

int main(int argc, char *argv[])
{
  while(1){
    *pGPIOC_BSRR = GPIO_BSRR13_SET;
    led_status = 0;
    for (uint32_t i =0; i < LED_DELAY; i++);
    *pGPIOC_BSRR = GPIO_BSRR13_RESET;
    led_status = 1;
    for (uint32_t i =0; i < LED_DELAY; i++);
  }
  return EXIT_SUCCESS;
}
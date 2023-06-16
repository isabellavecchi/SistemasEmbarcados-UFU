#include <stdlib.h>
#include <stdint.h>
// #include "config.h"

// Ctrl + Shift + B para pegar arquivos genéricos

// RCC: reset and clock control, ajusta a frequencia/periodo de execucao do meu compilador
/* AHB1 Base Addresses ******************************************************/

#define STM32_RCC_BASE       0x40023800     /* 0x40023800-0x40023bff: Reset and Clock control RCC */

/* GPIOC Base Addresses ******************************************************/

#define STM32_GPIOC_BASE     0x40020800     /* 0x48000800-0x48000bff: GPIO Port C */

/* Register Offsets *********************************************************/

/* typedef struct pinoGPIO_s(pino)
{
  /* data */
} pinoGPIO; */


#define STM32_RCC_AHB1ENR_OFFSET  0x0030   /* AHB1 Peripheral Clock enable
                                               register */

#define STM32_GPIO_MODER_OFFSET   0x0000  /* GPIO port mode register */
#define STM32_GPIO_OTYPER_OFFSET  0x0004  /* GPIO port output type register */
#define STM32_GPIO_PUPDR_OFFSET   0x000c  /* GPIO port pull-up/pull-down register */
#define STM32_GPIO_ODR_OFFSET     0x0014  /* GPIO port output data register */
#define STM32_GPIO_BSRR_OFFSET    0x0018  /* GPIO port bit set/reset register */


/* Register Addresses *******************************************************/

#define STM32_RCC_AHB1ENR        (STM32_RCC_BASE+STM32_RCC_AHB1ENR_OFFSET)

/* Output states: push-pull, or open drain + pull-up / pull-down */
#define STM32_GPIOC_MODER        (STM32_GPIOC_BASE+STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOC_OTYPER       (STM32_GPIOC_BASE+STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOC_PUPDR        (STM32_GPIOC_BASE+STM32_GPIO_PUPDR_OFFSET)

/* Output data from output data register GPIOx_ODR or peripheral (alternate function
output) */
#define STM32_GPIOC_ODR          (STM32_GPIOC_BASE+STM32_GPIO_ODR_OFFSET)

/* Bit set and reset register (GPIOx_ BSRR) for bitwise write access to GPIOx_ODR */
#define STM32_GPIOC_BSRR         (STM32_GPIOC_BASE+STM32_GPIO_BSRR_OFFSET)

/* AHB1 Peripheral Clock enable register */

#define RCC_AHB1ENR_GPIOCEN      (1 << 2)  /* Bit 2:  IO port C clock enable */

/* GPIO port mode register */

#define GPIO_MODER_INPUT           (0) /* Input */
#define GPIO_MODER_OUTPUT          (1) /* General purpose output mode */
#define GPIO_MODER_ALT             (2) /* Alternate mode */
#define GPIO_MODER_ANALOG          (3) /* Analog mode */

#define GPIO_MODER_SHIFT(n)        (n << 1)
#define GPIO_MODER_MASK(n)         (3 << GPIO_MODER_SHIFT(n))

/* GPIO port output type register */

#define GPIO_OTYPER_PP             (0) /* 0=Output push-pull */
#define GPIO_OTYPER_OD             (1) /* 1=Output open-drain */

#define GPIO_OT_SHIFT(n)           (n)
#define GPIO_OT_MASK(n)            (1 << GPIO_OT_SHIFT(n))

/* GPIO port pull-up/pull-down register */

#define GPIO_PUPDR_NONE            (0) /* No pull-up, pull-down */
#define GPIO_PUPDR_PULLUP          (1) /* Pull-up */
#define GPIO_PUPDR_PULLDOWN        (2) /* Pull-down */

#define GPIO_PUPDR_SHIFT(n)        (n << 1)
#define GPIO_PUPDR_MASK(n)         (3 << GPIO_PUPDR_SHIFT(n))

/* GPIO port bit set/reset register */

#define GPIO_BSRR_SET(n)           (1 << (n))
#define GPIO_BSRR_RESET(n)         (1 << ((n) + 16))

/* Configuration ************************************************************/

#define LED_DELAY  50000

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

 /****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int main(int argc, char *argv[])
{
  uint32_t reg, i;

  /* Ponteiros para registradores */

  uint32_t *pRCC_AHB1ENR  = (uint32_t *)STM32_RCC_AHB1ENR;
  uint32_t *pGPIOC_MODER  = (uint32_t *)STM32_GPIOC_MODER;
  uint32_t *pGPIOC_OTYPER = (uint32_t *)STM32_GPIOC_OTYPER;
  uint32_t *pGPIOC_PUPDR  = (uint32_t *)STM32_GPIOC_PUPDR;
  uint32_t *pGPIOC_BSRR   = (uint32_t *)STM32_GPIOC_BSRR;

  
  /* //Passo 1: copiar o reg numa variavel temp
  *pu32 = (uint32_t *)(STM32_RCC_AHB1ENR);
  reg = *pu32;
  //Passo 2: Resetar bits de interesse
  reg &= ~(1<<2); //1 deslocado em 2 casas = 0100
  //Passo 3: Setar bits de interesse
  reg |= (1<<2);
  //Passo 4: Escrever em reg o valor de temp
  *pu32 = reg; */


   /* Habilita clock GPIOC */
  reg = *pRCC_AHB1ENR;
  reg &= ~(1<<2); //1 deslocado em 2 casas = 0100
  reg |= (1<<2);
  *pRCC_AHB1ENR = reg;
  
  /* Configura PC13 como saida pull-up off e pull-down off */

  reg = *pGPIOC_MODER;
  reg &= ~GPIO_MODER_MASK(13);
  reg |= (GPIO_MODER_OUTPUT << GPIO_MODER_SHIFT(13));
  *pGPIOC_MODER = reg;  

  reg = *pGPIOC_OTYPER;
  reg &= ~GPIO_OT_MASK(13);
  reg |= (GPIO_OTYPER_PP << GPIO_OT_SHIFT(13));
  *pGPIOC_OTYPER = reg;

  reg = *pGPIOC_PUPDR;
  reg &= ~GPIO_PUPDR_MASK(13);
  reg |= (GPIO_PUPDR_NONE << GPIO_PUPDR_SHIFT(13));
  *pGPIOC_PUPDR = reg;

  while(1)
    {
      /* Liga LED */

      *pGPIOC_BSRR = GPIO_BSRR_RESET(13);
      for (i = 0; i < LED_DELAY; i++);

      /* Desliga LED */

      *pGPIOC_BSRR = GPIO_BSRR_SET(13);
      for (i = 0; i < LED_DELAY; i++);
    }

  /* Nunca deveria chegar aqui */

  return EXIT_FAILURE;
}
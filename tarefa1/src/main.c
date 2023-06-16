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

#define STM32_RCC_AHB1ENR_OFFSET  0x0030   /* AHB1 Peripheral Clock enable
                                               register */

#define STM32_GPIO_MODER_OFFSET   0x0000  /* GPIO port mode register */
#define STM32_GPIO_OTYPER_OFFSET  0x0004  /* GPIO port output type register */
#define STM32_GPIO_OSPEEDR_OFFSET 0x0008  /* GPIO port output speed register */
#define STM32_GPIO_PUPDR_OFFSET   0x000c  /* GPIO port pull-up/pull-down register */
// #define STM32_GPIO_IDR_OFFSET     0x0010  /* GPIO port input data register */
#define STM32_GPIO_ODR_OFFSET     0x0014  /* GPIO port output data register */
#define STM32_GPIO_BSRR_OFFSET    0x0018  /* GPIO port bit set/reset register */

// #define STM32_GPIO_AFRH_OFFSET    0x0024  /* GPIO alternate function high register (pinos 8->15) */


/* Register Addresses *******************************************************/

#define STM32_RCC_AHB1ENR        (STM32_RCC_BASE+STM32_RCC_AHB1ENR_OFFSET)

#define STM32_GPIOC_MODER        (STM32_GPIOC_BASE+STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOC_OTYPER       (STM32_GPIOC_BASE+STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOC_OSPEEDR      (STM32_GPIOC_BASE+STM32_GPIO_OSPEEDR_OFFSET)
#define STM32_GPIOC_PUPDR        (STM32_GPIOC_BASE+STM32_GPIO_PUPDR_OFFSET)
#define STM32_GPIOC_ODR          (STM32_GPIOC_BASE+STM32_GPIO_ODR_OFFSET)
// #define STM32_GPIOC_IDR          (STM32_GPIOC_BASE+STM32_GPIO_IDR_OFFSET)
#define STM32_GPIOC_BSRR         (STM32_GPIOC_BASE+STM32_GPIO_BSRR_OFFSET)

/* AHB1 Peripheral Clock enable register */

#define RCC_AHB1ENR_CRCEN_DISABLE  (0)
#define RCC_AHB1ENR_CRCEN_ENABLE   (1)

#define RCC_AHB1ENR_SHIFT          (2)  /* Bit 2:  IO port C clock enable/disable */
#define RCC_AHB1ENR_MASK           (1 << RCC_AHB1ENR_SHIFT)

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

#define GPIO_OTYPER_SHIFT(n)           (n)
#define GPIO_OTYPER_MASK(n)            (1 << GPIO_OTYPER_SHIFT(n))

/* GPIO port mode register */

#define GPIO_OSPEEDR_LOW            (0) /* Input */
#define GPIO_OSPEEDR_MEDIUM         (1) /* General purpose output mode */
#define GPIO_OSPEEDR_FAST           (2) /* Alternate mode */
#define GPIO_OSPEEDR_HIGH           (3) /* Analog mode */

#define GPIO_OSPEEDR_SHIFT(n)        (n << 1)
#define GPIO_OSPEEDR_MASK(n)         (3 << GPIO_OSPEEDR_SHIFT(n))

/* GPIO port pull-up/pull-down register */

#define GPIO_PUPDR_NONE            (0) /* No pull-up, pull-down */
#define GPIO_PUPDR_PULLUP          (1) /* Pull-up */
#define GPIO_PUPDR_PULLDOWN        (2) /* Pull-down */

#define GPIO_PUPDR_SHIFT(n)        (n << 1)
#define GPIO_PUPDR_MASK(n)         (3 << GPIO_PUPDR_SHIFT(n))

/* GPIO port output data register */
#define GPIO_ODR_SHIFT(n)           (n)
#define GPIO_ODR_MASK(n)            (1 << GPIO_ODR_SHIFT(n))

/* GPIO port bit set/reset register */

#define GPIO_BSRR_SET(n)           (1 << (n))
#define GPIO_BSRR_RESET(n)         (1 << ((n) + 16))

/* Configuration ************************************************************/

#define LED_DELAY  50000

/****************************************************************************
 * Private Types
 ****************************************************************************/
uint32_t* struct_pointer;


/* typedef struct (uint32_t pin, uint32_t moder, uint32_t otyper, uint32_t pupdr)
{
} pinoGPIO_t; */


/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

 /****************************************************************************
 * Private Functions
 ****************************************************************************/
void escreveBit(uint32_t *addr, uint32_t val, uint32_t mask, uint32_t shift) {
  uint32_t reg = *addr;
  reg &= ~(mask);
  reg |= (val << shift);
  *addr = reg;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

// IMPLEMENTAR FUNCAO DE INICIALIZACAO DE TODOS OS PINOS AO ESTE ARQUIVO SER UTILIZADO
// EVITANDO PINOS FLUTUANTES

int main(int argc, char *argv[])
{
  uint32_t i;
  /* Ponteiros para registradores */
  // nota: o pino PC13 nao possui alternate function
  
  /* Habilita clock GPIOC */
  
  escreveBit((uint32_t *)STM32_RCC_AHB1ENR, RCC_AHB1ENR_CRCEN_ENABLE, RCC_AHB1ENR_MASK, RCC_AHB1ENR_SHIFT);


  /* Configura PC13 como saida Push/Pull com pull-up off e pull-down off */
  escreveBit((uint32_t *)STM32_GPIOC_MODER, GPIO_MODER_OUTPUT, GPIO_MODER_MASK(13), GPIO_MODER_SHIFT(13));

  escreveBit((uint32_t *)STM32_GPIOC_OTYPER, GPIO_OTYPER_PP, GPIO_OTYPER_MASK(13), GPIO_OTYPER_SHIFT(13));

  escreveBit((uint32_t *)STM32_GPIOC_PUPDR, GPIO_PUPDR_NONE, GPIO_PUPDR_MASK(13), GPIO_PUPDR_SHIFT(13));


  /* Configura velocidade do pino em LOW-SPEED */

  escreveBit((uint32_t *)STM32_GPIOC_OSPEEDR, GPIO_OSPEEDR_LOW, GPIO_OSPEEDR_MASK(13), GPIO_OSPEEDR_SHIFT(13));


  uint32_t *pGPIOC_BSRR   = (uint32_t *)STM32_GPIOC_BSRR;
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
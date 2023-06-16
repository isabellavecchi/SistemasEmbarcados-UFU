#include "sketch.h"

#define GPIO_LED 0;
#define LOW 0;
#define HIGH 1;
#define LED_DELAY 50000;

void setup(void)
{
    pinMode(GPIO_LED, OUTPUT);
}
/* para configurar um pino:
qual a porta
qual a saída
modo
pull up, pull down
... */
void loop(void)
{
    /* Liga LED */
    digitalWrite(GPIO_LED, LOW);
    for(int i=0; i<LED_DELAY; i++);

    /* Desliga LED */
    digitalWrite(GPIO_LED, HIGH);
    for(int i=0; i<LED_DELAY; i++);
}
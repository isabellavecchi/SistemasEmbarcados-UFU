/* led.h

 *
 *  Created on: 16 de mai de 2023
 *      Author: Isabella Vecchi Ferreira
 *
 */

#ifndef INC_PERIPHERALS_LED_H_
#define INC_PERIPHERALS_LED_H_

#include <hw_GPIO.h>


void ledToggle(void);
void ledEnable(void);
void ledDisable(void);
bool getLedState(void);

void setLEDCallbackFn(void (*callback)(void));

#endif /* INC_PERIPHERALS_LED_H_ */

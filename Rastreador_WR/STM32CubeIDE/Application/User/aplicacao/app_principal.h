#ifndef APP_PRINCIPAL_H
#define APP_PRINCIPAL_H

#include "stm32l4xx_hal.h"

/* LED da NUCLEO-L476RG */
#define LED_STATUS_PIN   GPIO_PIN_5
#define LED_STATUS_PORT  GPIOA

void app_principal_iniciar(void);

#endif

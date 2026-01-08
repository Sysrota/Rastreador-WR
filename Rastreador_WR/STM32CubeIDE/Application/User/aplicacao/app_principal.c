#include "app_principal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32l4xx_hal.h"

/* Handle da task */
static TaskHandle_t tarefa_led_handle = NULL;

/* Task do LED
   - 2 segundos ligado
   - 1 segundo desligado
*/
static void tarefa_led(void *argumentos)
{
  for (;;)
  {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    vTaskDelay(pdMS_TO_TICKS(2000));

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

/* Função chamada pelo FreeRTOS */
void app_principal_iniciar(void)
{
  xTaskCreate(
    tarefa_led,            // Função da task
    "LED",                 // Nome
    128,                   // Stack
    NULL,                  // Parâmetros
    tskIDLE_PRIORITY + 1,  // Prioridade
    &tarefa_led_handle     // Handle
  );
}

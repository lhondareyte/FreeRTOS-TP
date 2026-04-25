#if defined(__AVR_ATmega32U4__)
#include "FreeRTOSVariant.h"
#endif

#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"
#include "common.h"   /* uart_puts, Led_*, Usart1_Init */

/* ── Mutex partagé ──────────────────────────────────────── */
static SemaphoreHandle_t xUartMutex;

/* ── Hooks obligatoires ─────────────────────────────────── */
void vApplicationIdleHook(void) { }   /* requis car configUSE_IDLE_HOOK = 1 */

void vApplicationMallocFailedHook(void) {
	uart_puts("\r\nMALLOC_FAIL\r\n");
	while (1);
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pName) {
	uart_puts("\r\nSTACK_OVF:");
	uart_puts(pName);
	while (1);
}

/* ── Tâche 1 — LED 1 ────────────────────────────────────── */
static void vTask1(void *dummy)
{
	TickType_t xLastWake = xTaskGetTickCount();
	const TickType_t xPeriod = pdMS_TO_TICKS(500);

	while (1) {
		Led_Hi1();
		xSemaphoreTake(xUartMutex, portMAX_DELAY);
		uart_puts("[T1] LED1 ON\r\n");
		xSemaphoreGive(xUartMutex);

		vTaskDelay(pdMS_TO_TICKS(250));

		Led_Lo1();
		xSemaphoreTake(xUartMutex, portMAX_DELAY);
		uart_puts("[T1] LED1 OFF\r\n");
		xSemaphoreGive(xUartMutex);

		xTaskDelayUntil(&xLastWake, xPeriod);
	}
}

/* ── Tâche 2 — LED 2 ────────────────────────────────────── */
static void vTask2(void *dummy)
{
	TickType_t xLastWake = xTaskGetTickCount();
	const TickType_t xPeriod = pdMS_TO_TICKS(700);

	while (1) {
		Led_Hi2();
		xSemaphoreTake(xUartMutex, portMAX_DELAY);
		uart_puts("[T2] LED2 ON\r\n");
		xSemaphoreGive(xUartMutex);

		vTaskDelay(pdMS_TO_TICKS(350));

		Led_Lo2();
		xSemaphoreTake(xUartMutex, portMAX_DELAY);
		uart_puts("[T2] LED2 OFF\r\n");
		xSemaphoreGive(xUartMutex);

		xTaskDelayUntil(&xLastWake, xPeriod);
	}
}

/* ── main ───────────────────────────────────────────────── */
int main(void)
{
	Usart1_Init();
	Led_Init();

	/* 1. Mutex en premier, avant toute tâche */
	xUartMutex = xSemaphoreCreateMutex();
	if (xUartMutex == NULL) goto hell;

	/* 2. Création des tâches */
	if (pdPASS != xTaskCreate(vTask1, "Task1", 128, NULL, 1, NULL)) goto hell;
	if (pdPASS != xTaskCreate(vTask2, "Task2", 128, NULL, 2, NULL)) goto hell;

	uart_puts("FreeRTOS start\r\n");

	/* 3. Démarrage — ne revient jamais */
	vTaskStartScheduler();

hell:
	uart_puts("ERREUR DEMARRAGE\r\n");
	while (1);
	return 0;
}

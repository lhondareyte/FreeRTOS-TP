#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
#include <avr/io.h>

#define configUSE_PREEMPTION              1
#define configUSE_IDLE_HOOK               1   /* obligatoire avec FreeRTOSVariant.h */
#define configUSE_TICK_HOOK               0
#define configCPU_CLOCK_HZ                F_CPU
/* configTICK_RATE_HZ est défini par FreeRTOSVariant.h via le WDT — ne pas redéfinir */
#define configMAX_PRIORITIES              4
#define configMINIMAL_STACK_SIZE          85
#define configTOTAL_HEAP_SIZE             1536
#define configMAX_TASK_NAME_LEN           8
#define configUSE_TRACE_FACILITY          0
#define configUSE_16_BIT_TICKS            1
#define configIDLE_SHOULD_YIELD           1
#define configUSE_MUTEXES                 1
#define configUSE_TIMERS                  0
#define configCHECK_FOR_STACK_OVERFLOW    2
#define configUSE_MALLOC_FAILED_HOOK      1

#define INCLUDE_vTaskDelay                1
#define INCLUDE_vTaskDelete               1
#define INCLUDE_uxTaskGetStackHighWaterMark 1
#define INCLUDE_xTaskDelayUntil           1
#define INCLUDE_vSemaphoreDelete          1
#endif

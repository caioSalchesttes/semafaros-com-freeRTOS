/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

SemaphoreHandle_t xSemaforo;

void tarefa1(void *pvParameter)
{
    while(1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 1] Executou - Caio\n");
            fflush(stdout);
            
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            
            xSemaphoreGive(xSemaforo);
        }
        
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void tarefa2(void *pvParameter)
{
    while(1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 2] Executou - Caio\n");
            fflush(stdout);
            
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            
            xSemaphoreGive(xSemaforo);
        }
        
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void tarefa3(void *pvParameter)
{
    while(1) {
        if (xSemaphoreTake(xSemaforo, portMAX_DELAY) == pdTRUE) {
            printf("[Tarefa 3] Executou - Caio\n");
            fflush(stdout);
            
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            
            xSemaphoreGive(xSemaforo);
        }
        
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    printf("=== Aplicacao FreeRTOS com Semaforos ===\n");
    printf("Iniciando 3 tarefas intercaladas...\n\n");

    xSemaforo = xSemaphoreCreateBinary();
    
    if (xSemaforo == NULL) {
        printf("Erro: Nao foi possivel criar o semaforo!\n");
        return;
    }
    
    xSemaphoreGive(xSemaforo);

    // Cria as 3 tarefas
    xTaskCreate(tarefa1, "Tarefa1", 2048, NULL, 1, NULL);
    xTaskCreate(tarefa2, "Tarefa2", 2048, NULL, 1, NULL);
    xTaskCreate(tarefa3, "Tarefa3", 2048, NULL, 1, NULL);

    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

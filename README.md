# Aplicação FreeRTOS com Semáforos - ESP32

**Nome:** Caio  
**Sala:** [Inserir sua sala]  
**RM:** [Inserir seu RM]

## Descrição

Esta aplicação demonstra o uso de semáforos no FreeRTOS para ESP32, implementando 3 tarefas que executam de forma intercalada com intervalo de 1 segundo entre elas.

## Funcionalidades

- 3 tarefas FreeRTOS executando concorrentemente
- Uso de semáforo binário para sincronização entre tarefas
- Execução intercalada das tarefas com intervalo de 1 segundo
- Saída formatada no console serial

## Exemplo de Saída

```
=== Aplicacao FreeRTOS com Semaforos ===
Iniciando 3 tarefas intercaladas...

[Tarefa 1] Executou - Caio
[Tarefa 2] Executou - Caio
[Tarefa 3] Executou - Caio
[Tarefa 1] Executou - Caio
[Tarefa 2] Executou - Caio
[Tarefa 3] Executou - Caio
...
```

## Estrutura do Projeto

```
├── CMakeLists.txt
├── main/
│   ├── CMakeLists.txt
│   └── hello_world_main.c      Código principal com implementação das tarefas
├── README.md                   Este arquivo
└── sdkconfig.ci
```

## Como Compilar e Executar

1. Configure o ESP-IDF:
```bash
idf.py set-target esp32
idf.py menuconfig
```

2. Compile o projeto:
```bash
idf.py build
```

3. Grave no ESP32:
```bash
idf.py -p [PORT] flash
```

4. Monitore a saída serial:
```bash
idf.py -p [PORT] monitor
```

## Implementação Técnica

### Semáforos
O projeto utiliza um semáforo binário (`xSemaphoreCreateBinary()`) para controlar o acesso exclusivo ao recurso compartilhado (saída serial).

### Tarefas
- **Tarefa 1, 2 e 3**: Cada uma tenta adquirir o semáforo, executa sua operação, aguarda 1 segundo e libera o semáforo
- **Prioridade**: Todas as tarefas têm a mesma prioridade (1)
- **Stack Size**: 2048 bytes para cada tarefa

### Sincronização
- `xSemaphoreTake()`: Adquire o semáforo (bloqueia até estar disponível)
- `xSemaphoreGive()`: Libera o semáforo para outras tarefas
- `vTaskDelay()`: Implementa os delays de 1 segundo e pausa entre tentativas

## Print da Execução

[Inserir aqui o print da execução quando testado]

## Targets Suportados

| ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
|-------|----------|----------|----------|----------|-----------|----------|----------|----------|----------|
| ✅     | ✅        | ✅        | ✅        | ✅        | ✅         | ✅        | ✅        | ✅        | ✅        |

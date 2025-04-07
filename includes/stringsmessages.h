#ifndef STRINGSMESSAGES_H
#define STRINGSMESSAGES_H

// Mensajes de ayuda y errores de argumentos
#define HELP_MESSAGE "Uso: ./programa [-h] | [-f ruta_config.txt]\n"
#define PARAMS_ERROR "Error: Número de parámetros incorrecto\n"
#define EMPTY_NAME "Error: Nombre de archivo vacío\n"
#define NAME_ERROR "Error: Nombre de archivo inválido\n"
#define FOPEN_ERROR "Error: No se pudo abrir el archivo\n"

// Opciones de comando
#define CHAR_H "-h"
#define STRING_H "--help"
#define CHAR_F "-f"
#define STRING_F "--file"

// Configuración
#define CONFIG_NUMBERS "numbers_per_thread"
#define CONFG_THREAD "thread_num"

// Mensajes de limpieza de recursos
#define CLEAN_RESOURCES "Limpiando recursos...\n"
#define CANCELING_THREADS "Cancelando hilos activos (%d hilos)...\n"
#define THREAD_CANCELED "- Hilo %d cancelado exitosamente\n"
#define THREAD_CANCEL_FAIL "- No se pudo cancelar el hilo %d (error: %d)\n"
#define THREAD_END_SUCCESS "- Hilo %d terminado correctamente\n"
#define THREAD_JOIN_FAIL "- No se pudo unir al hilo %d, continuando...\n"
#define FREE_EVEN_LIST "Liberando lista de números pares...\n"
#define NODES_COUNT_EVEN "- %d nodos en la lista de pares\n"
#define FREE_ODD_LIST "Liberando lista de números impares...\n"
#define NODES_COUNT_ODD "- %d nodos en la lista de impares\n"
#define CLEAN_COMPLETE "Limpieza de recursos completada.\n"

// Mensajes de señales
#define SIGINT_ERROR "Error al configurar el manejador para SIGINT\n"
#define SIGTERM_ERROR "Error al configurar el manejador para SIGTERM\n"
#define SIGNAL_RECEIVED "\nRecibida señal %d, terminando hilos...\n"
#define PROGRAM_INTERRUPTED "\nPrograma interrumpido por señal. Terminando...\n"

// Mensajes de listas
#define EVEN_LIST_HEADER "\nLista PARES:\n"
#define ODD_LIST_HEADER "\nLista IMPARES:\n"

// Mensajes de prueba
#define TEST_CREATE_LIST "test_crearte_list : %d\n"
#define TEST_GEN_NUMBERS "test_generate_unique_numbers : %d\n"

// Mensajes de configuración
#define CONFIG_VALID "Configuración válida:\n"
#define CONFIG_THREAD_COUNT "Número de hilos: %d\n"
#define CONFIG_NUMBERS_COUNT "Números por hilo: %d\n"
#define CONFIG_INVALID "Configuración inválida.\n"

// Mensajes de archivo
#define CONFIG_FILE_PATH "El archivo de configuración es: %s\n"

// Mensajes de hilos y memoria
#define THREAD_MEMORY_ERROR "Error: No se pudo asignar memoria para los datos del hilo\n"
#define THREAD_CREATE_ERROR "Error: No se pudo crear el hilo %d\n"

#endif
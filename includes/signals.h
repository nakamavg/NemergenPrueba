#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <stdbool.h>
#include "linked_list.h"
#include <pthread.h>

// Variable global que indica si el programa debe terminar
extern volatile sig_atomic_t program_running;

// Variables para tracking de recursos
extern Node **global_even_list;
extern Node **global_odd_list;
extern pthread_t *global_threads;
extern int global_thread_count;

// Inicializa el manejo de señales
void setup_signal_handlers(void);

// Manejador de señales
void signal_handler(int signum);

// Función para registrar recursos para limpieza
void register_resources(Node **even_list, Node **odd_list, pthread_t *threads, int thread_count);

// Función para limpiar recursos antes de terminar
void cleanup_resources(void);

#endif

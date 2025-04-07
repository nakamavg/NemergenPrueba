#include "signals.h"
#include "stringsmessages.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile sig_atomic_t program_running = 1;

Node **global_even_list = NULL;
Node **global_odd_list = NULL;
pthread_t *global_threads = NULL;
int global_thread_count = 0;

/**
 * @brief Configura los manejadores de señales para SIGINT y SIGTERM
 */
void setup_signal_handlers(void) {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    
    sigaddset(&sa.sa_mask, SIGINT);
    sigaddset(&sa.sa_mask, SIGTERM);
    
    sa.sa_flags = 0;
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror(SIGINT_ERROR);
        exit(1);
    }
    
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror(SIGTERM_ERROR);
        exit(1);
    }
}

/**
 * @brief Manejador que se ejecuta cuando se recibe una señal
 */
void signal_handler(int signum) {
    if (program_running) {
        printf(SIGNAL_RECEIVED, signum);
        program_running = 0;
    }
}

/**
 * @brief Registra los recursos que deben limpiarse al terminar el programa
 */
void register_resources(Node **even_list, Node **odd_list, pthread_t *threads, int thread_count) {
    global_even_list = even_list;
    global_odd_list = odd_list;
    global_threads = threads;
    global_thread_count = thread_count;
}

/**
 * @brief Limpia los recursos del programa antes de terminar
 */
void cleanup_resources(void) {
    printf(CLEAN_RESOURCES);
    
    if (global_even_list != NULL && *global_even_list != NULL) {
        printf(FREE_EVEN_LIST);
        int count = 0;
        Node *current = *global_even_list;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        printf(NODES_COUNT_EVEN, count);
        free_list(global_even_list);
        *global_even_list = NULL;
    }
    
    if (global_odd_list != NULL && *global_odd_list != NULL) {
        printf(FREE_ODD_LIST);
        int count = 0;
        Node *current = *global_odd_list;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        printf(NODES_COUNT_ODD, count);
        free_list(global_odd_list);
        *global_odd_list = NULL;
    }
    
    printf(CLEAN_COMPLETE);
}

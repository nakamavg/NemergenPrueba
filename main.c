#include "arguments.h"
#include "nemergent.h"
#include "linked_list.h"
#include "threads.h"
#include "signals.h"
#include "stringsmessages.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
 * @brief Función principal del programa
 *
 * Esta función coordina todo el flujo del programa:
 * 1. Configura los manejadores de señal
 * 2. Valida los argumentos de línea de comandos
 * 3. Lee la configuración desde un archivo
 * 4. Inicializa las listas enlazadas y la barra de progreso
 * 5. Crea y ejecuta los hilos de procesamiento
 * 6. Espera a que los hilos terminen
 * 7. Imprime los resultados
 * 8. Libera los recursos
 *
 * @param argc Número de argumentos de línea de comandos
 * @param argv Array de strings con los argumentos
 * @return 0 en caso de éxito, otro valor en caso de error
 */
int main(int argc, char **argv) {
    setup_signal_handlers();

    int result = check_args(argc, argv);
    if (result == 1) return result;

    Config config = read_config(argv[2]);
    if (!config.valid) return 1;

    Node *even_list = NULL;
    Node *odd_list = NULL;

    init_loading_bar(config.thread_num * config.numbers_per_thread);

    pthread_t threads[config.thread_num];
    int threads_created = 0; 
    
    register_resources(&even_list, &odd_list, NULL, 0);
    
    for (int i = 0; i < config.thread_num && program_running; i++) {
        ThreadData *data = malloc(sizeof(ThreadData));
        if (!data) {
            fprintf(stderr, THREAD_MEMORY_ERROR);
            break;
        }
        
        data->seed = time(NULL) + i;
        data->count = config.numbers_per_thread;
        data->even_list = &even_list;
        data->odd_list = &odd_list;
        
        if (pthread_create(&threads[i], NULL, thread_function, data) == 0) {
            threads_created++; 
        } else {
            free(data); 
            fprintf(stderr, THREAD_CREATE_ERROR, i);
            break;
        }
    }

    for (int i = 0; i < threads_created; i++) {
        pthread_join(threads[i], NULL);
    }

    if (!program_running) {
        printf(PROGRAM_INTERRUPTED);
        cleanup_resources();
    }
    
    if (program_running) {
        printf(EVEN_LIST_HEADER);
        print_list(even_list);
        printf(ODD_LIST_HEADER);
        print_list(odd_list);
    }

    free_list(&even_list);
    free_list(&odd_list);

    return 0;
}
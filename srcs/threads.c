#include "../includes/threads.h"
#include "../includes/signals.h"
#include <unistd.h> 

/**
 * @brief Función principal que ejecuta cada hilo
 *
 * Esta función genera números aleatorios únicos y los clasifica en
 * listas de números pares e impares. Muestra el progreso mediante
 * una barra de carga y se detiene si recibe una señal.
 *
 * @param arg Puntero a la estructura ThreadData con los datos del hilo
 * @return NULL al finalizar
 */
void* thread_function(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    int *nums = generate_unique_numbers(data->count, &data->seed);
    
    for (int i = 0; i < data->count && program_running; i++) {
        if (nums[i] % 2 == 0) {
            safe_insert(data->even_list, nums[i]);
        } else {
            safe_insert(data->odd_list, nums[i]);
        }
        
        update_loading_bar(1);
        
        usleep(1000);
    }
    
    free(nums);
    free(data);
    return NULL;
}
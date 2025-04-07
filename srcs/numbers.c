#include "numbers.h"
#include <stdlib.h>
#include <pthread.h>

// Global variables for tracking progress
static pthread_mutex_t loading_bar_mutex = PTHREAD_MUTEX_INITIALIZER;
static int total_operations = 0;
static int completed_operations = 0;
static bool loading_bar_initialized = false;

/**
 * @brief Verifica si un número es par
 *
 * @param number Número a verificar
 * @return true si el número es par, false si es impar
 */
bool is_even(int number)
{
    return number % 2 == 0;
}

/**
 * @brief Genera un array de números aleatorios únicos
 *
 * Crea un array de 'count' números aleatorios únicos en un rango adecuado.
 * El rango se adapta según la cantidad de números solicitados para evitar
 * colisiones y bucles infinitos.
 *
 * @param count Cantidad de números a generar
 * @param seed Puntero a la semilla para la generación de números aleatorios
 * @return Puntero al array de números (debe liberarse con free)
 */
int *generate_unique_numbers(int count, unsigned int *seed)
{
    int range = count * 10;
    if (range < 1000) range = 1000;

    int *nums = malloc(count * sizeof(int));
    if (!nums) return NULL;
    
    if (count > 100000) {
        for (int i = 0; i < count; i++) {
            nums[i] = rand_r(seed) % range;
        }
    } else {
        bool *used = calloc(range, sizeof(bool));
        if (!used) {
            free(nums);
            return NULL;
        }
        
        for (int i = 0; i < count; i++) {
            int num;
            int attempts = 0;
            do {
                num = rand_r(seed) % range;
                attempts++;
                if (attempts > 1000) break;
            } while (used[num]);
            
            used[num] = true;
            nums[i] = num;
        }
        
        free(used);
    }
    
    return nums;
}

/**
 * @brief Inicializa la barra de progreso con el total de operaciones
 *
 * @param total Número total de operaciones que se van a realizar
 */
void init_loading_bar(int total)
{
    pthread_mutex_lock(&loading_bar_mutex);
    total_operations = total;
    completed_operations = 0;
    loading_bar_initialized = true;
    pthread_mutex_unlock(&loading_bar_mutex);
}

/**
 * @brief Actualiza la barra de progreso con el progreso actual
 *
 * @param increment Cantidad de operaciones completadas desde la última actualización
 */
void update_loading_bar(int increment)
{
    pthread_mutex_lock(&loading_bar_mutex);
    
    completed_operations += increment;
    
    static int update_frequency = 1;
    static int last_update = 0;
    
    if (total_operations > 1000000) {
        update_frequency = total_operations / 1000;
    }
    
    if (completed_operations - last_update >= update_frequency || 
        completed_operations >= total_operations) {
        
        last_update = completed_operations;
        
        int bar_width = 50;
        float progress = (float)completed_operations / total_operations;
        int pos = bar_width * progress;
        
        printf("\r[");
        for (int i = 0; i < bar_width; i++) {
            if (i < pos) printf("=");
            else printf(" ");
        }
        printf("] %.2f%%", progress * 100);
        
        if (completed_operations >= total_operations) {
            printf("\n");
        }
        
        fflush(stdout);
    }
    
    pthread_mutex_unlock(&loading_bar_mutex);
}

/**
 * @brief Muestra una barra de progreso para indicar el avance de una tarea
 *
 * Esta función es compatible con versiones anteriores y ahora utiliza
 * el sistema centralizado de barra de progreso.
 *
 * @param total Total de operaciones a realizar
 * @param current Número de operaciones completadas hasta el momento
 */
void loading_bar(int total, int current)
{
    static int local_total = 0;
    
    if (current == 1 || local_total == 0) {
        local_total = total;
        if (!loading_bar_initialized) {
            init_loading_bar(total);
        }
    }
    
    static int last_current = 0;
    if (current > last_current) {
        update_loading_bar(current - last_current);
        last_current = current;
    }
}
#include "../includes/threads.h"

// threads.c
void* thread_function(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    int *nums = generate_unique_numbers(data->count, &data->seed);

    for (int i = 0; i < data->count; i++) {
        if (nums[i] % 2 == 0) {
            safe_insert(data->even_list, nums[i]); // Lista de pares
        } else {
            safe_insert(data->odd_list, nums[i]);  // Lista de impares
        }
    }

    free(nums);
    free(data);
    return NULL;
}
#include "numbers.h"
#include <stdlib.h>
bool is_even(int number)
{
    return number % 2 == 0;
}
/**
 * Genera 'count' números aleatorios únicos en el rango [0, 999].
 * @param count Cantidad de números a generar.
 * @return Array de números únicos (malloc), o NULL en caso de error.
 */
int *generate_unique_numbers(int count, unsigned int *seed)
{
    int *nums = malloc(count * sizeof(int));
    bool *used = calloc(1000, sizeof(bool));

    for (int i = 0; i < count; i++)
    {
        int num;
        do
        {
            num = rand_r(seed) % 1000;
        } while (used[num]);
        used[num] = true;
        nums[i] = num;
    }

    free(used);
    return nums;
}
#ifndef NUMBERS_H
#define NUMBERS_H
#include "nemergent.h"
#include <stdbool.h>

bool is_even(int number);
int* generate_unique_numbers(int count, unsigned int *seed);
void loading_bar(int total, int current);

// New centralized loading bar functions
void init_loading_bar(int total);
void update_loading_bar(int increment);

#endif
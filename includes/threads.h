#ifndef THREADS_H
#define THREADS_H

#include "linked_list.h"
#include <pthread.h>
#include <stdlib.h>
#include "numbers.h"

typedef struct {
    unsigned int seed;    // Semilla única por hilo
    int count;            // Números a generar
    Node **even_list;          // Lista compartida de pares
    Node **odd_list;           // Lista compartida de impares
} ThreadData;

void* thread_function(void *arg);


#endif
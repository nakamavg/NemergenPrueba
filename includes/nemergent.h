#ifndef NEMERGENT_H
#define NEMERGENT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include  "stringsmessages.h"
#include "linked_list.h"
#include "threads.h"

#define STDOUT 1
#define STDERR 2
#define CHAR_INVALID 4
typedef struct {
    int numbers_per_thread;
    int thread_num;
    int valid;
} Config;
//srcs/arguments.c
void print_m(FILE *fd ,char *message);
int check_args(int argc, char **argv);
//srcs/config.c
Config read_config(const char *filename);
# endif
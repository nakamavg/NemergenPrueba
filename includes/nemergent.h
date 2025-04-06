#ifndef NEMERGENT_H
#define NEMERGENT_H

#include <stdio.h>
#include <string.h>
#include  "stringsmessages.h"
#define STDOUT 1
#define STDERR 2
#define CHAR_INVALID 4

//srcs/utils.c
void print_m(FILE *fd ,char *message);
int check_args(int argc, char **argv);
# endif
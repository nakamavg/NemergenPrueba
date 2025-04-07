#include "nemergent.h"
#include <string.h>
#include <stdbool.h>

/**
 * @brief Imprime un mensaje en el flujo de salida especificado.
 */
void print_m(FILE *fd, char *message)
{
    fprintf(fd, "%s", message);
}

/**
 * @brief Verifica si un argumento coincide con un carácter o una opción.
 */
int check_argument(char *argv, char *character, char *option)
{
    if(strcmp(argv, character) == 0 || strcmp(argv, option) == 0)
        return 1;
    else
        return 0;
}

/**
 * Valida si un archivo tiene extensión .txt.
 */
bool validate_file_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    
    if (!dot || dot == filename || strcmp(dot + 1, "txt") != 0) {
        return false;
    }
    return true;
}

/**
 * @brief Verifica y procesa los argumentos de línea de comandos.
 */
int check_args(int argc, char **argv)
{
    if (argc == 1 || argc > 3)
    {
        print_m(stderr, PARAMS_ERROR);
        return 1;
    }

    if (argc == 2)
    {
        if (check_argument(argv[1], CHAR_H, STRING_H))
        {
            print_m(stdout, HELP_MESSAGE);
            return 1;
        }
        
        print_m(stderr, PARAMS_ERROR);
        return 1;
    }

    if (!validate_file_extension(argv[2]))
    {
        print_m(stderr, NAME_ERROR);
        return 1;
    }
    
    if (check_argument(argv[1], CHAR_F, STRING_F))
    {
        char message[100];
        sprintf(message, "El archivo de configuración es: %s\n", argv[2]);
        print_m(stdout, message);
        return 2;
    }

    print_m(stderr, PARAMS_ERROR);
    return 1;
}
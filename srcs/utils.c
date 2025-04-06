#include "nemergent.h"
/**
 * @brief Imprime un mensaje en el flujo de salida especificado.
 *
 * Esta función toma un flujo de salida (por ejemplo, stdout o un archivo)
 * y un mensaje de texto, y escribe el mensaje en el flujo proporcionado.
 *
 * @param fd Puntero al flujo de salida donde se imprimirá el mensaje.
 *           Puede ser stdout, stderr o un archivo abierto con fopen.
 * @param message Cadena de texto que se imprimirá en el flujo de salida.
 *                Debe ser una cadena terminada en null ('\0').
 *
 * @note Es responsabilidad del llamador asegurarse de que el flujo de salida
 *       esté correctamente abierto antes de llamar a esta función.
 * @note Si el flujo de salida no es válido, el comportamiento de la función
 *       es indefinido.
 */
void print_m(FILE *fd ,char *message)
{
    fprintf(fd, "%s", message);
}

/**
 * @brief Verifica si el número de argumentos de línea de comandos es válido.
 *
 * Esta función comprueba si la aplicación fue invocada con un número válido de
 * argumentos en la línea de comandos. Los valores válidos para argc son 2 o 3
 * (lo que corresponde a uno o dos parámetros además del nombre del programa).
 * 
 * Si el número de argumentos no es válido (ninguno o más de dos parámetros),
 * la función imprime un mensaje de error en stderr.
 *
 * @param argc Número de argumentos pasados en la línea de comandos.
 * @return int Retorna 1 si el número de parámetros es inválido (error),
 *             retorna 0 si el número de parámetros es correcto.
 * 
 * @note Esta función no analiza el contenido o validez de los parámetros,
 *       solo verifica su cantidad.
 */
 int check_args(int argc)
{
    if (argc == 1 || argc > 3)
    {
        print_m(stderr, PARAMS_ERROR);
        return 1;
    }
    return 0;
}
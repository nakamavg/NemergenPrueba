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

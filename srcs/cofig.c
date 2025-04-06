#include "../includes/nemergent.h"

/**
 * @brief Lee y valida la configuración desde un archivo
 *
 * Esta función analiza un archivo de configuración para extraer los parámetros requeridos.
 * Solo acepta líneas con configuraciones de "numbers_per_thread" y "thread_num",
 * y verifica que no haya contenido inesperado en el archivo.
 * Las líneas vacías y líneas que solo contienen espacios en blanco son ignoradas.
 *
 * @param filename Ruta al archivo de configuración a leer
 * @return Estructura Config que contiene los ajustes analizados y el estado de validación
 *         El campo 'valid' será 0 si ocurrió algún error de análisis o faltan valores requeridos
 */
Config read_config(const char *filename) {
    Config config = {0, 0, 0};
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror(FOPEN_ERROR);
        return config;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int empty = 1;
        for (int i = 0; line[i]; i++) {
            if (!isspace((unsigned char)line[i])) {
                empty = 0;
                break;
            }
        }
        if (empty) continue;
        
        int value;
        int matched = 0;
        char extra[100] = {0};
        
        if (sscanf(line, " numbers_per_thread = %d %s", &value, extra) == 1) {
            config.numbers_per_thread = value;
            matched = 1;
        } 
        else if (sscanf(line, " thread_num = %d %s", &value, extra) == 1) {
            config.thread_num = value;
            matched = 1;
        }        
        if (!matched) {
            config.valid = 0;
            fclose(file);
            return config;
        }
    }

    fclose(file);
    config.valid = (config.numbers_per_thread > 0 && config.thread_num > 0);
    return config;
}
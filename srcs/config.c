#include "nemergent.h"

/**
 * @brief Lee y valida la configuración desde un archivo
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
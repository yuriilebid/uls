#include "libmx.h"

char *mx_strnew(int size) {
    char *memory = (char *)malloc(size + 1);

    if (memory == NULL) {
        char *msg = "malloc error\n";
        write(2, msg, mx_strlen(msg));
        return NULL;
    }

    for (int i = 0; i < size + 1; i++)
        memory[i] = '\0';
    return memory;
}

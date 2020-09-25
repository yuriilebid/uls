#include "uls.h"

void mx_newline(char **specified_dirs, int i) {
    if (specified_dirs[i + 1] != NULL)
        mx_printstr("\n");
}



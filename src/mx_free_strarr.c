#include "uls.h"

// Freeing memmory of strarr
void mx_free_strarr(char **strarr) {
    if (strarr) {
        for (int i = 0; i < mx_strarr_size(strarr); ++i) {
            free(strarr[i]);
        }
        free(strarr);
    }
}

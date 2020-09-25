#include "libmx.h"

// Allocates mem. for array of strings.
char **mx_new_strarr(int number_of_str) {
    char **arr = (char **)malloc((number_of_str + 1) * sizeof(char *));
    if (arr == NULL) {
        char *msg = "malloc error\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    arr[number_of_str] = NULL;
    return arr;
}

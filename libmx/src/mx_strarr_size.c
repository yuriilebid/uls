#include "libmx.h"

// Counts size of array of strings.
int mx_strarr_size(char **arr) {
    int counter = 0;

    while(arr[counter])
        counter++;
    return counter;
}

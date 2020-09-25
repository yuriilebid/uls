#include "libmx.h"

int mx_strlen(const char *s) {
    int length_of_string = 0;

    while(s[length_of_string])
        length_of_string++;
    return length_of_string;
}

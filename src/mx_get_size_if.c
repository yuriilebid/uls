#include "uls.h"

static char *itoas(int number) {
    if(number == 0) {
        char *result = mx_strnew(1);

        result[0] = '0';
        return result;
    }
    else {
        long number2 = number;
        int len = 0;
        return mx_itoas_addition(number, number2, len);
    }
}

static char* beetween_space(char* s1, int major, int max) {
    char *result = mx_strnew(8);
    char *output;

    result[0] = ',';
    for(int i = 0; i < max - (((major + 1) + mx_strlen(s1))); i++)
        result[i + 1] = ' ';
    output = result;
    return output;
}

char *mx_get_size_if(t_files* list, char* hex, int* size_all) {
    char *del;
    char *result;
    char *minor = itoas(MINOR(list -> stats.st_rdev));;
    char *major;

    major = itoas(MAJOR(list -> stats.st_rdev));
    if(MINOR(list -> stats.st_rdev) > 255)
        hex = mx_high_minor(hex, list, major, minor);
    else {
        hex = mx_three_join(major, 
        del = beetween_space(minor, size_all[6], size_all[4]), minor);
        free(del);
    }
    free(major);
    free(minor);
    size_all[8] = 4;
    result = hex;
    free(hex);
    return result;
}

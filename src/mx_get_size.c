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

char *mx_get_size(t_files* list, char* dir, int* size_all) {
    char *mode = mx_file_mode(list -> stats, list -> file_name, dir);
    char *result;
    char *hexadecimalNumber;

    if(list -> stats.st_size == 0)
        hexadecimalNumber = "0";
    else
    hexadecimalNumber = itoas(list -> stats.st_size);

    if(mode[0] == 'c' || mode[0] == 'b')
        hexadecimalNumber = mx_get_size_if(list, hexadecimalNumber, size_all);
    result = hexadecimalNumber;
    if(list -> stats.st_size != 0)
        free(hexadecimalNumber);
    return result;
}

#include "uls.h"

static char *add_oct_prefix(char* string) {
    char *name = mx_strnew(10);

    name[0] = '0';
    name[1] = 'x';
    for(int i = 2; i < 10; i++)
        name[i] = '0';
    for(int i = 10 - mx_strlen(string), j = 0; string[j]; i++, j++)
        name[i] = string[j];
    return name;
}

static char* dec_hex(int decimalNumber, char* hexadecimalNumber) {
    long int quotient;
    int i = 0;
    int temp;

    quotient = decimalNumber;
    while(quotient != 0) {
        temp = quotient % 16;
        if( temp < 10)
            temp =temp + 48;
        else
            temp = temp + 87;
        hexadecimalNumber[i++]= temp;
        quotient = quotient / 16;
    }
    hexadecimalNumber[i] = '\0';
    return hexadecimalNumber;
}

char *mx_high_minor(char* hexadecimalNumber, 
    t_files *list, char *major, char *minor) {
    char *hex;

    hexadecimalNumber = mx_strnew(30);
    hex = dec_hex(MINOR(list -> stats.st_rdev), hexadecimalNumber);
    minor = add_oct_prefix(hex);
    hexadecimalNumber = mx_three_join(major, ", ", minor);
    free(hex);
    free(minor);
    return hexadecimalNumber;
}

#include "uls.h"

char *mx_itoas_addition(int number, long number2, int len) {
    char *result = mx_strnew(100);

    if(number < 0)
        number2 *= -1;
    while(number2 != 0) {
        number2 = number2/10;
        len++;
    }
    if(number < 0)
        len++;
    if(number < 0) {
        result[0] = '-';
        number *= -1;
    }
    while(number != 0){
        result[len - 1] = number % 10 + 48;
        number = number / 10;
        len--;
    }
    return result;
}

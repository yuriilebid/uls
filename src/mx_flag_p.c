#include "uls.h"

/*
 * implementation of flag -p 
 * prints / after file name if it is directory 
 */
void mx_flag_p(t_files *files, char *flags) {
    if (mx_is_in_arr(flags, 'p') && files -> type == 'd')
        mx_printstr("/");
}

#include "uls.h"

/*
 * Checks, whether file/direcory 
 * should be printed depending on flags specified -A or -a. 
 */

static int hidden_file_checker(char *dir_name, char *flags) {
    if (dir_name[0] == '.' && mx_is_in_arr(flags, 'R') == 0)
        return 1;
    return 0;
}

/* 
 * Checks wether dir_name path is hidden file
 *  if dir_name = ./.git, return 1
 *  if dir_name = ./dir1, return 0
 */
static int hidden_path_checker(char *dir_name) {
    for (int i = 0; i < mx_strlen(dir_name) - 1; ++i) {
        if (dir_name[i] == '/' && dir_name[i + 1] == '.')
            return 1;
    }
    return 0;
}

int mx_a_checker(char *dir_name, char *flags) { 
    if (mx_is_in_arr(flags, 'a') == 0 ) {
        if (mx_strcmp(dir_name, ".") == 0 
            || mx_strcmp(dir_name, "..") == 0
            || hidden_file_checker(dir_name, flags)
            || hidden_path_checker(dir_name)) {
            return 1;
        }
    }
    return 0;
}


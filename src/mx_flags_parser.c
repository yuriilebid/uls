#include "uls.h"

/* 
 * Findes flags, which user specified in his/her input.
 * In case of unsupportable flags specified, function returns NULL
 */

/* 
 * This func. returns starting index of specified flag. 
 * returns 0 if there is no flags specified
 */
static int flags_start(int argc, char **argv) {
    if (argc > 1) {
        if (argv[1][0] == '-')
            return 1;
    }
    return 0;
}

/* 
 * Returns last index of specified flag. 
 * returns 0 if there is no flags specified
 */
static int flags_end(int argc, char **argv) {
    int index = 0;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (argv[i][0] != '-' || mx_strcmp(argv[i], "-") == 0) 
                break;
            else
                index = i;
        }
    }
    return index;
}

static void illegal_option(char option) {
    char *text1 = ("uls: illegal option -- ");
    char *text2 = ("usage: uls [-l] [file ...]");
    write(2, text1, mx_strlen(text1));
    write(2, &option, 1);
    write(2, "\n", 1);
    write(2, text2, mx_strlen(text2));
    write(2, "\n", 1);
    exit(1);
}

// Finds errors in flag output 
static int wrong_flag_input(char **argv, 
    int start_index, int end_index) {
    int i = start_index;
    char *avaliable_flags = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";

    for (; i <= end_index ; i++) {
        if (mx_char_in_arr_counter(argv[i], '-') > 1) {
            if (mx_strlen(argv[i]) > 2)
                illegal_option('-');
            else if (mx_strlen(argv[i]) == 2)
                break;
        }
        else
            for (int j = 1; j < mx_strlen(argv[i]); j++) {
                if (mx_is_in_arr(avaliable_flags, argv[i][j]) == 0)
                    illegal_option(argv[i][j]);
            }
    }
    return i;
}

char *mx_flags_parser(int argc, char **argv) {
    int start_index = flags_start(argc, argv);
    int end_index   = flags_end(argc, argv);
    char *flags = NULL;
    int new_end_index;
    char *tmp;

    if (start_index == 0 && end_index == 0)
        return " ";
    new_end_index = wrong_flag_input(argv, start_index, end_index);
    for (int i = start_index; i < new_end_index ; i++) {
            tmp = mx_strjoin(flags, argv[i]);
            free(flags);
            flags = tmp;
    }
    if (flags == NULL)
        return " ";
    return flags;
}

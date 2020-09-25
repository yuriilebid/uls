#include "uls.h"

static int returns(t_files *files) {
    if (files == NULL || 
        (files -> next == NULL && files -> file_name == NULL)) {
        return 1;
    }   
    return 0;
}

/*
 * This is second section of implementing ls.
 * Here we have got:
 *  files - list of files, which are needed to be listed.
 *      files are sorted in right(ascending) order
 *      flags - sting, which consists of all flags, user has specified.
 */
void mx_second_section(t_files *files, char *flags, char *dir) {
    int where_output = isatty(1);

    if (returns(files))
        return;
    files = files -> next;
    if (mx_is_in_arr(flags, 'm'))
        mx_flag_m(files, flags, dir);
    else if (mx_is_in_arr(flags, '1'))
        mx_minus_one(files, flags, dir);
    else if(mx_is_in_arr(flags, 'l') || mx_is_in_arr(flags, 'o') || 
        mx_is_in_arr(flags, 'g'))
        mx_flag_l_output(files, dir, flags);
    else if(where_output == 0 && mx_is_in_arr(flags, 'C') == 0)
        mx_minus_one(files, flags, dir);
    else
        mx_pure_output(files, flags, dir);
    mx_printstr("\n");
}

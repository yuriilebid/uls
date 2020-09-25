#include "uls.h"

// Implementation of flag -R



static void name_printer(char *dir_name, int checker) {
    if (checker != 0) {
        mx_printstr(dir_name);
        mx_printstr(":\n");
    }
}

//  Main recursion function
static void recursion_maker(char *dir_name, char *flags, int checker) {
    t_files *files = mx_files_list_maker(dir_name, flags);
    char **list_of_dir = mx_list_of_dirs(dir_name);;

    name_printer(dir_name, checker);
    checker++;
    mx_second_section(files, flags, dir_name);
       
    mx_tfiles_freesher(files);
    if (list_of_dir != NULL) {
        mx_quicksort_strarr(list_of_dir, 0, mx_strarr_size(list_of_dir) - 1);
        for (int i = 0; i < mx_strarr_size(list_of_dir); ++i) {
            if (mx_error(list_of_dir[i]))
                continue;
            if (mx_a_checker(list_of_dir[i], flags) == 1)        
                continue;
            if (list_of_dir[i] != NULL)
                write(1, "\n", 1);
            recursion_maker(list_of_dir[i], flags, checker);
        }
        mx_free_strarr(list_of_dir);
    }
}

void mx_recursion(char **specified_dirs, char *flags) {
    int ch = 0;
    t_files *files;

    if (mx_strarr_size(specified_dirs) > 1)
        ch++;
    for (int i = 0; i < mx_strarr_size(specified_dirs); ++i) {
        if (mx_error(specified_dirs[i])) 
            continue;
        if (mx_type(specified_dirs[i])  == 'd') 
            recursion_maker(specified_dirs[i], flags, ch);
        else {
            files = mx_files_list_maker(specified_dirs[i], flags);
            mx_second_section(files, flags, specified_dirs[i]); 
            if (specified_dirs[i + 1] != NULL)
                if (mx_type(specified_dirs[i + 1])  == 'd')
                    write(1, "\n", 1);
            mx_tfiles_freesher(files);
        }
    }
}

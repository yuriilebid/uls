#include "uls.h"

/*
 * Prints directory name if:
 *      - user specified more than 1 directory.
 *      - if dir_name is directory (not file/socket etc.)
 */
static void dir_name_printer(char *dir_name, char **specified_dirs) {
    struct stat Stat;
    stat(dir_name, &Stat);

    if (mx_strarr_size(specified_dirs) > 1 && 
        mx_file_type(dir_name, Stat) == 'd') {
        mx_printstr(dir_name);
        mx_printstr(":\n");
    }
}

static void d_flag(char **specified_dirs, char *flags) {
     t_files *files = mx_flag_d(specified_dirs);
    mx_second_section(files, flags, NULL);
    while(files){
        t_files *tmp = files;
        files = files->next;
        free(tmp);
    }
}


/* 
 * Iterate through sorted array of directories user
 * has specified.
 * On each iteration it:
 *  a) checks whether specified dir/file is valid. 
 *    (permission not denied/ file exists etc.)
 *    if dir. not valid - it is skipped.
 *  b) creates (linked) list of content of specified dir.
 *     it is carried out with mx_file_list_maker() func.
 *  c) calls mx_second_section() - handles output of dir`s content
 *      more details: src/main/mx_second_section
 */
static void mx_tdirs_handler(char **specified_dirs, char *flags) {
    int i = 0;

    if (mx_is_in_arr(flags, 'd') == 0)
        while(specified_dirs[i]) {
            if (mx_error(specified_dirs[i])) {
                i++;
                continue;
            }
            t_files *files = mx_files_list_maker(specified_dirs[i], flags);
            dir_name_printer(specified_dirs[i], specified_dirs);
            mx_second_section(files, flags, specified_dirs[i]);
            if (specified_dirs[i + 1] != NULL)
                write(1, "\n", 1);
            mx_tfiles_freesher(files); 
            i++;
    }
    else {
        d_flag(specified_dirs, flags);
    }
}

/* 
 * Determines, which directories user has specified.
 * Depending on flags, user has specified, views this directories. 
 */
void mx_directories(int argc, char **argv, char *flags) {
    char **specified_dirs = mx_specified_directories(argc, argv);

    mx_quicksort_strarr(specified_dirs, 0, mx_strarr_size(specified_dirs) - 1);
    if (mx_is_in_arr(flags, 'R'))
       mx_recursion(specified_dirs, flags);
    else 
        mx_tdirs_handler(specified_dirs, flags);
    free(specified_dirs);
}

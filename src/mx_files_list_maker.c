#include "uls.h"

/*
 * Creates t_files list.
 * It represents all files contained in the directory dir_name.
 */
t_files *mx_files_list_maker(char *dir_name, char *flags) {
    char *path = NULL;
    t_files *files = mx_create_tfiles(NULL);
    char **list_of_files;

    if (mx_error(dir_name))
        return files;
    else if (mx_is_directory(dir_name) == 0 || 
            (mx_type(dir_name) == 'l' && mx_is_in_arr(flags, 'l'))) {
        mx_push_back_tfiles(&files, mx_string_copy(dir_name));
        return files;
    }
    list_of_files = mx_list_of_files(dir_name, flags, path);
    if (list_of_files == NULL) 
        return files;
    mx_quicksort_strarr(list_of_files, 0, mx_strarr_size(list_of_files) - 1);
    for (int i = 0; i < mx_strarr_size(list_of_files); ++i)
        mx_push_back_tfiles(&files, list_of_files[i]);
    free(list_of_files);
    return files;
}

#include "uls.h"

/* 
 * Function, which adds / to the name of directory in case there is
 *  no slash. If there is /, / is not added
 * d_name argument is entry -> d_name
 */
static char *slash_adder(char *dir, char *d_name) {
    char *file_path;

    if (dir[mx_strlen(dir) - 1] != '/') {
        file_path = mx_three_join(dir, "/", d_name);
    }
    else {
        file_path = mx_strjoin(dir, d_name);
    }
    return file_path;
}

// Checks wether file is needed to be hide.
static int is_to_hide(char *file_name, char *flags) {
    if (mx_is_in_arr(flags, 'a') == 0 && mx_is_in_arr(flags, 'A') == 0) {
      if (mx_strcmp(file_name, ".") == 0 
            || mx_strcmp(file_name, "..") == 0
            || file_name[0] == '.')
            return 1;
    }
    else if (mx_is_in_arr(flags, 'A') == 1)
        if  (mx_strcmp(file_name, ".") == 0 
            || mx_strcmp(file_name, "..") == 0)
            return 1;
    return 0;
}


// Counts the number of files in directory dir_name.
static int number_of_files(char *dir_name, char *flags) {
    DIR *dir_opn = opendir(dir_name);
    struct dirent *entry;
    int num = 0;

    if (mx_permission_denied(dir_name))
        return 0;
    while ((entry = readdir(dir_opn))!= NULL)
       if (is_to_hide(entry -> d_name, flags) == 0) 
            num++;
    closedir(dir_opn);
    return num;
}

/* 
 * Returns array of strings, which respresent all files contained 
 *  in directory (dir_name).
 * In case of permission denied for dir_name -> return NULL
 */
char **mx_list_of_files(char *dir_name, char *flags, char* file_path) {
    int num_of_files = number_of_files(dir_name, flags);
    if (num_of_files == 0)
        return NULL;
    char **list_of_files = mx_new_strarr(num_of_files);
    DIR *dir_opn = opendir(dir_name);
    struct dirent *entry;
    int index = 0;

    if (mx_error(dir_name))
        return NULL;
    while ((entry = readdir(dir_opn)) != NULL) {
        file_path = slash_adder(dir_name, entry -> d_name);
        if (is_to_hide(entry -> d_name, flags) == 0) {    
            list_of_files[index] = mx_string_copy(file_path);
            index++;
        }
        free(file_path);
    }
    closedir(dir_opn);
    return list_of_files;
}

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

// Counts the number of directories in specified directory <dir> 
static int number_of_dirs(char *dir) {
    DIR *dir_opn = opendir(dir);
    struct dirent *entry;
    struct stat Stat;
    int num = 0;
    char *file_path;

    while ((entry = readdir(dir_opn))!= NULL) {
        file_path = slash_adder(dir, entry -> d_name);
        stat(file_path, &Stat);
        if (mx_file_type(file_path, Stat) == 'd'
            && mx_strcmp(entry -> d_name, ".") != 0
            && mx_strcmp(entry -> d_name, "..") != 0) {
            num++;
        }
        free(file_path);
    }
    closedir(dir_opn);
    return num;
}

/*
 * Creates array of all directories(str data type),
 * that are located in directory <dir>
 */
char **mx_list_of_dirs(char *dir) {
    int num_of_dirs = number_of_dirs(dir);
    if (num_of_dirs == 0)
        return NULL;
    char **list_of_dirs = mx_new_strarr(num_of_dirs);
    DIR *dir_opn = opendir(dir);
    struct dirent *entry;
    struct stat Stat;
    int index = 0; // index, where to append new element to array

    while ((entry = readdir(dir_opn))!= NULL) {
        char *file_path = slash_adder(dir, entry -> d_name);
        stat(file_path, &Stat);
        if (mx_file_type(file_path, Stat) == 'd'  
            && mx_strcmp(entry -> d_name, ".") != 0 
            && mx_strcmp(entry -> d_name, "..") != 0) {
            list_of_dirs[index] = file_path;
            index++;
        }
        else 
           free(file_path);
    }
    closedir(dir_opn);
    return list_of_dirs;
}















#include "uls.h"

// Finds the last slash index.
static int last_slash_finder(char *file_path) {
    int len = mx_strlen(file_path) - 2;

    while (len >= 0) {
        if (file_path[len] == '/') {
            return len;
        }
        len--;
    }
    return -1;
}

/*
 * This function retrieves file_name from file_path
 * Example:
 * Input: ../dir1/dir2/dir3/dir4/dir5/dirx/file
 * Output: file
 */
char *mx_file_name_retriever(char *file_path) {
    int last_slash_index;
    int x;
    char *f_name;
    int index;

    if (file_path == NULL)
        return NULL;
    last_slash_index = last_slash_finder(file_path);
    if (last_slash_index == -1)
        return NULL;   
    x = mx_strlen(file_path) - last_slash_index;
    f_name = mx_strnew(x);
    index = 0;
    while (file_path[last_slash_index + 1]) {
        f_name[index] = file_path[last_slash_index + 1];
        index++;
        last_slash_index++;
    }
    return f_name;  
}

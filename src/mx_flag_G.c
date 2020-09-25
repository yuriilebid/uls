#include "uls.h"

static char *three_joins(char *str1, char *str2, char *str3) {
    int len = mx_strlen(str1) + mx_strlen(str2) + mx_strlen(str3);
    char* result = mx_strnew(len);
    int index = 0;

    for(; index < mx_strlen(str1); index++)
        result[index] = str1[index];
    for(int i = 0; i < mx_strlen(str2); index++, i++)
        result[index] = str2[i]; 
    for(int i = 0; i < mx_strlen(str3); index++, i++)
        result[index] = str3[i]; 
    return result;
}

static void change_filename(t_files* list, char* color) {
    char *result = three_joins(color, list -> file_name, "\x1b[0m");
    
    mx_printstr(result);
    free(result);
}

static void flag_G_add(t_files* tmp, char* path) {
    if(mx_file_type(path, tmp -> stats) == 'b')
        change_filename(tmp, "\x1b[34m\x1b[46m");
    else if(mx_file_type(path, tmp -> stats) == 'p')
        change_filename(tmp, "\x1b[33m");
}

void mx_flag_G(t_files* list, char* dir) {
    t_files* tmp = list;
    char* path;

    path = mx_three_join(dir, "/", tmp -> file_name);
    if(mx_file_type(path, tmp -> stats) == 'd')
        change_filename(tmp, "\x1b[34m");
    else if(mx_file_type(path, tmp -> stats) == 's')
        change_filename(tmp, "\x1b[32m");
    else if(mx_file_type(path, tmp -> stats) == 'l')
        change_filename(tmp, "\x1b[35m");
    else if(mx_file_type(path, tmp -> stats) == 'c')
        change_filename(tmp, "\x1b[34m\x1b[43m");
    else if(tmp -> stats.st_mode & S_IXUSR)
        change_filename(tmp, "\x1b[31m");
    else
        flag_G_add(tmp, path);
    free(path);
}

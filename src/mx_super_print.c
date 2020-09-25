#include "uls.h"

static int flag_G_check(t_files* tmp, char* dir) {
    char* path;
    int ret = 0;

    path = mx_three_join(dir, "/", tmp -> file_name);
    if(mx_file_type(path, tmp -> stats) == 'd')
        ret = 1;
    else if(mx_file_type(path, tmp -> stats) == 's')
        ret = 1;
    else if(mx_file_type(path, tmp -> stats) == 'l')
        ret = 1;
    else if(mx_file_type(path, tmp -> stats) == 'c')
        ret = 1;
    else if(tmp -> stats.st_mode & S_IXUSR)
        ret = 1;
    else if(mx_file_type(path, tmp -> stats) == 'b')
        ret = 1;
    else if(mx_file_type(path, tmp -> stats) == 'p')
        ret = 1;
    free(path);
    return ret;
}

static void print_tab(char* string, int space_size) {
    int tabs = (space_size - mx_strlen(string)) / 8;

    if((space_size - mx_strlen(string)) % 8 != 0)
        tabs++;
    for(int i = 1; i <= tabs; i++)
        write(1, "\t", 1);
}

// Prints spaces after each printed filename
static void prints(char* string, int space_size) {
    for(int i = 1; i < space_size - mx_strlen(string); i++)
        mx_printstr(" ");
}

/*
 * Finds the longest file-
 * name in f_list and returns its 
 * length. 
 */
static int longs(t_files *list) {
    int longest_filename = 0;
    t_files* tmp = list;

    while (tmp) {
        if(tmp->file_name != NULL) {
            if(mx_strlen(tmp->file_name) > longest_filename)
                longest_filename = mx_strlen(tmp->file_name);
        }
        tmp = tmp -> next;
    }
    return longest_filename;
}

void mx_super_print(t_files *list, int i, char *arr[mx_count_list(list)],
    char *flags, char *dir) {
    t_files *tmp = list;

    for(int j = 0; mx_strcmp(tmp -> file_name, arr[i]) != 0; j++)
        tmp = tmp -> next;
    if(mx_is_in_arr(flags, 'G')) {
        if(flag_G_check(tmp, dir)) {
            mx_flag_G(tmp, dir);
            prints(arr[i], longs(list) + 2);
        }
        else {
            mx_printstr(arr[i]);
            prints(arr[i], longs(list) + 2);
        }
    }
    else {
        mx_printstr(arr[i]);
        print_tab(arr[i], longs(list) + (8 - (longs(list) % 8)));
    }
}

#include "uls.h"

/*
 * Function prints special number 
 * of spaces after each mx_prinstr
 * function usage.
 */
static void spaces(int len_diff1, int len_diff2, int standart_space) {
    for(int i = 1; i < standart_space + len_diff1 + len_diff2; i++)
        mx_printstr(" ");
}

/*
 * Function returns int array of 
 * lenghtes of each output data in
 * a single file, on witch we 
 * reference in f_list* list node
 * length of (mode, link, user...)
 */
static int *get_curent_data_length(t_files* i, char* dir, int* l, int* a) {
    char *del;

    l[0] = mx_strlen(mx_file_mode(i -> stats, i -> file_name, dir));
    l[1] = mx_getint_len(i -> stats.st_nlink);
    l[2] = mx_strlen(mx_getuser(i -> stats.st_uid));
    l[3] = mx_strlen(mx_get_stgid(i));
    l[4] = mx_strlen(mx_get_size(i, dir, a));
    if(l[4] > 7)
        l[4] = 7;
    l[5] = mx_strlen(del = mx_convert_date(ctime(&i -> stats.st_mtime), i));
    free(del);
    return l;
}

void mx_flag_l_out_add(t_files *l, char *dir, char *f, int l1[9], int l2[8]) {
    char *del;

    get_curent_data_length(l, dir, l2, l1);
    mx_printstr(mx_file_mode(l -> stats, l -> file_name, dir));
    spaces(l1[0] - l2[0], l1[1] - l2[1], 2);
    mx_printstr(mx_itoa(l -> stats.st_nlink));
    if (mx_is_in_arr(f, 'g') == 0) {
        spaces(l1[1] - l1[1], l1[2] - l1[2], 2);
        mx_printstr(mx_getuser(l -> stats.st_uid));
    }
    if (mx_is_in_arr(f, 'o') == 0) {
    spaces(l1[2]- l2[2], l1[3]- l1[3], 3);
    mx_printstr(mx_get_stgid(l));
    }
    spaces(l1[3] - l2[3], l1[4] - l2[4], 3);
    mx_printstr(mx_get_size(l, dir, l1));
    spaces(l1[4] - l1[4], l1[5] - l1[5], 2);
    mx_printstr(del = mx_convert_date(ctime(&l -> stats.st_mtime), l));
    free(del);
    spaces(l1[5] - l1[5], l1[5] - l1[5], 2);
}

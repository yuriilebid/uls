#include "uls.h"

int *mx_each_l_add(int* l, t_files* tmp, char* d) {
    char *del;

    if(mx_strlen(mx_file_mode(tmp -> stats, tmp -> file_name, d)) > l[0])
        l[0] = mx_strlen(mx_file_mode(tmp -> stats, tmp -> file_name, d));
    if(mx_getint_len(tmp -> stats.st_nlink) > l[1])
        l[1] = mx_getint_len(tmp -> stats.st_nlink);
    if(mx_strlen(mx_getuser(tmp -> stats.st_uid)) > l[2])
        l[2] = mx_strlen(mx_getuser(tmp -> stats.st_uid));
    if(mx_strlen(mx_get_stgid(tmp)) > l[3])
        l[3] = mx_strlen(mx_get_stgid(tmp));
    if(mx_strlen(mx_itoa(tmp -> stats.st_size)) > l[4])
        l[4] = mx_strlen(mx_get_size(tmp, d, l));
    if(mx_strlen(del = mx_convert_date(ctime(&tmp -> stats.st_mtime), 
       tmp)) > l[5]) {
        free(del);
        l[5] = mx_strlen(del = mx_convert_date(ctime(&tmp -> stats.st_mtime),
        tmp));
    }
    free(del);
    return l;
}

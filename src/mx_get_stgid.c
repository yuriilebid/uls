#include "uls.h"

char *mx_get_stgid(t_files *list) {
    struct group *g = getgrgid(list -> stats.st_gid);
    char *result;

    if (g != NULL)
        return g -> gr_name;
    else
        result = mx_itoa(list -> stats.st_gid);
    return result;
}

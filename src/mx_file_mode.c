#include "uls.h"

static char mode_access(char *path, char *name, char* dir) {
    ssize_t bufflen;
    char *path1 = path;
    acl_t acl = NULL;
    dir = NULL;

    bufflen = listxattr(path1, name, (ssize_t)0, XATTR_NOFOLLOW);
    acl = acl_get_file(path1, ACL_TYPE_EXTENDED);
    free(acl);
    if(bufflen > 0)
        return '@';
    else if(acl != NULL)
        return '+';
    else 
        return ' ';
}

char *mx_file_mode(struct stat Stat, char *name, char* path) {
    char *mode = mx_strnew(11); 
    char *result;
    char* road = mx_three_join(path, "/", name);

    mode[0] = mx_file_type(path, Stat);
    if (mx_link(road, Stat))
        mode[0] = 'l';
    mode = mx_file_mode_add(Stat, mode);
    mode[10] = mode_access(road, name, path);
    result = mode;
    free(road);
    free(mode);
    return result;
}

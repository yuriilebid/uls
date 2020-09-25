#include "uls.h"

/*
 * Determines type of the file
 * return vulue:
 * d if directory
 * l if link
 * - if common file
 * s if socket
 */
char mx_type(char *file_path) {
    struct stat Stat;
    stat(file_path, &Stat);
    char type;

    type = Stat.st_mode & S_IFIFO ? 'p': '-';
    type = Stat.st_mode & S_IFSOCK ? 's': type;
    type = Stat.st_mode & S_IFCHR ? 'b': type;
    type = Stat.st_mode & S_IFDIR ? 'd': type;
    type = Stat.st_mode & S_IFCHR ? 'c': type;
    type = Stat.st_mode & S_IFREG ? '-': type;
    if (mx_link(file_path, Stat))
        type = 'l';
    return type;
}

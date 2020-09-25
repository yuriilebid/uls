#include "uls.h"

/*
 * Determines type of the file
 *  return vulue:
 *      d if directory
 *      l if link
 *      - if common file
 *      s if socket
 */
char mx_file_type(char *file_path, struct stat Stat) {
    char type = '\0';

    if (S_IFCHR == ( S_IFMT & Stat.st_mode))
        type = 'c';
    else if (S_IFBLK == ( S_IFMT & Stat.st_mode))
         type = 'b';
    else if (S_IFIFO == ( S_IFMT & Stat.st_mode))
        type = 'p';
    else if (S_IFREG == ( S_IFMT & Stat.st_mode))
        type = '-';
    else if (S_IFSOCK == ( S_IFMT & Stat.st_mode))
        type = 's';
    else if (S_IFDIR == ( S_IFMT & Stat.st_mode))
        type = 'd';
    else if (mx_link(file_path, Stat))
        type = 'l';
    return type;
}

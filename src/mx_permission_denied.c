#include "uls.h"

// Prints error message for "permission denied error"
static void permission_denied_error(char *dir_name) {
    errno = 13;
    char *text1 = "uls: ";
    write(2, text1, mx_strlen(text1));
    perror(dir_name);
    errno = 0;
}

/*
 * Checks whether file is accessible
 * if no access -> return 1
 */
int mx_permission_denied(char *dir_name) {
    errno = 0;
    DIR *dir = opendir(dir_name);

    if (errno == 0)
        closedir(dir);
    else if (errno == 13) {
        permission_denied_error(dir_name);
        free(dir);
        return 1;
    }
    else 
        free(dir);
    return 0;
}

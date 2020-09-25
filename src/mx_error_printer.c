#include "uls.h"


// Check dir_name for being bad file descriptor(errno 9)
static int bad_descriptor(char *dir_name) {    
    errno = 0;
    DIR *dir_opn = opendir(dir_name);

    if (errno == 9) {
        mx_printstr("uls: ");
        perror(dir_name);
        errno = 0;
        free(dir_opn);
        return 1;
    }
    if (errno == 0)
        closedir(dir_opn);
    else
        free(dir_opn);
    errno = 0;
    return 0;
}

/* 
 * Error message
 * File/Directory does not exists
 */
static void mx_file_or_directory_not_exists(char *file) {
    errno = 2;
    char *text1 = "uls: ";

    write(2, text1, mx_strlen(text1));
    perror(file);
    errno = 0;
}

// Checks whether file is accessible
static int permission_denied_check(char *dir_name) {
    errno = 0;
    DIR *dir = opendir(dir_name);

    if (errno == 0)
        closedir(dir);
    else if (errno == 13) {
        free(dir);
        return 1;
    }
    else 
        free(dir);
    return 0;
}

// Prints error messages
int mx_error_printer(char *dir_name) {
    if (permission_denied_check(dir_name))
        return 1;
    else if (mx_file_exists(dir_name) == 0) {
        mx_file_or_directory_not_exists(dir_name);
        return 1;
    }
    else if (bad_descriptor(dir_name))
        return 1;
    return 0;
}

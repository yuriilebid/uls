#include "uls.h"

char* mx_file_mode_add(struct stat Stat, char *mode) {
    mode[1] = Stat.st_mode & MX_S_IRUSR ? 'r' : '-';
    mode[2] = Stat.st_mode & MX_S_IWUSR ? 'w' : '-';
    mode[3] = Stat.st_mode & MX_S_IXUSR ? 'x' : '-';
    mode[4] = Stat.st_mode & MX_S_IRGRP ? 'r' : '-';
    mode[5] = Stat.st_mode & MX_S_IWGRP ? 'w' : '-';
    mode[6] = Stat.st_mode & MX_S_IXGRP ? 'x' : '-';
    mode[7] = Stat.st_mode & MX_S_IROTH ? 'r' : '-';
    mode[8] = Stat.st_mode & MX_S_IWOTH ? 'w' : '-';
    mode[9] = Stat.st_mode & MX_S_IXOTH ? 'x' : '-';
    return mode;
}

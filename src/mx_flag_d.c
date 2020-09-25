#include "uls.h"

// Implementation of flag -d
t_files *mx_flag_d(char **specified_dirs) {
    t_files *files = mx_create_tfiles(NULL);    

    int i = 0;
    while(specified_dirs[i]) {
        mx_push_back_tfiles(&files, specified_dirs[i]);
        i++;
    }
    return files;
}

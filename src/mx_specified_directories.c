#include "uls.h"

/* 
 * This func. determines all the directories,
 * which were specified by the user.
 * return: {"dir1", "dir2", "dir3" ... "dirX"}
 * In case of no specified directoies
 * return: {"."}
 */
char **mx_specified_directories(int argc, char **argv) {
    char **specified_directories = NULL;
    int index = mx_argv_index(argc, argv);
    int num_dirs = argc - index; // Number of specified directories.
    
    if (index == 0) {
        specified_directories = mx_new_strarr(1);
        *specified_directories = ".";
        return specified_directories;
    }
    specified_directories = mx_new_strarr(num_dirs);
    for (int i = 0; i < num_dirs; ++i) {
        specified_directories[i] = argv[index];
        index++;
    }
    return specified_directories;
}

#include "uls.h"

/*
 * Finds argv index of specified directory/file.
 * User >>> ./uls -Ra dir1 dir2 dir2
 *   Output: 2
 * User >>> ./uls file1
 *  Output: 1
 * In case of no specified directories/files returns 0
 * User >>> ./uls -la
 *      Output: 0
 */

int mx_argv_index(int argc, char *argv[]) {
    int argv_index = 0;
    int step = 1;
    int stop_flags_inputer = 0;

    while (argv_index + step < argc) {
        if (argv[argv_index + step][0] != '-' 
            || mx_strcmp(argv[argv_index + step], "-") == 0 
            || stop_flags_inputer == 1) {
            argv_index = argv_index + step;
            break;
        }
        else if (mx_strcmp(argv[argv_index + step], "--") == 0) {
            stop_flags_inputer += 1;
        }
        step += 1;
    }
    return argv_index;
}

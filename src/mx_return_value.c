#include "uls.h"

/*  
 * This functional determines which 
 * value the programm will return.
 * if specified directory does not exist, 
 * mx_return_value returns 1, else returns 0.
 */
int mx_return_value(int argc, char **argv) {
    int index = mx_argv_index(argc, argv);
    int error_occured;

    if (index == 0)
        return 0;
    error_occured = 0;
    for (int i = index; i < argc; ++i) {
        if (mx_error_printer(argv[i]) )
            error_occured += 1;
    }
    if(error_occured > 0)
        return 1;
    return 0;
}

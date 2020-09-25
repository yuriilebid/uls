#include "uls.h"

/*
 * This is help function, which is used in Debug goals
 * in order to print list (t_files)
 */
void mx_files_printer(t_files *files) {
    
    t_files *tmp = files;
    while(tmp) {
        if (tmp -> file_name) {
            write(1,"\t",1);
            mx_printstr(tmp -> file_name);
            write(1,"\n",1);
        }
        tmp = tmp -> next;
    }
}

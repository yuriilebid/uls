#include "uls.h"

void mx_print_total(t_files *list) {
    t_files *ptr = list;
    int total = 0;

    while(ptr) {
        if(ptr -> file_name)
            total += ptr -> stats.st_blocks;
        ptr = ptr -> next;
    }
    mx_printstr("total ");
    mx_printstr(mx_itoa(total));
    mx_printstr("\n");
}

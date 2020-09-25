#include "uls.h"

static char **sort_uls_help(int count, char *s[count], 
                        char *fl[count], int cols) {
    int in = 0;
    int mem = in;
    int rows = count / cols;

    if(count % cols != 0)
        rows += 1;
    for(int i  = 0; i < count; i++) {
        if(in + mem >= count) {
            in = 0;
            mem++;
        }
        s[i] = fl[in + mem];
        in += rows;
    }
    return s;
}


// Sorts array for pure output.
char** mx_sort_output(int count, t_files* list, int cols, char *s[count]) {
    t_files* tmp = list;
    int i = 0;
    char* filearr[count];
    tmp = list;

    while(tmp) {
        if(tmp -> file_name != NULL) {
            filearr[i] = tmp->file_name;
            i++;
        }
        tmp = tmp -> next;
    }
    s = sort_uls_help(count, s, filearr, cols);
    return s;
}

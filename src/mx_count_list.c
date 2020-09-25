#include "uls.h"

// Countes number of nodes in list.
int mx_count_list(t_files* list) {
    int count = 0;
    t_files *tmp = list;

    while(tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

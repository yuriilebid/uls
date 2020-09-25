#include "uls.h"

/*
 * Function count number of files 
 * in linked list.
 */
static int count_files(t_files* list) {
    int count = 0;
    t_files *tmp = list;

    while(tmp) {
        count++;
        tmp = tmp -> next;
    }
    return count;
}

/*
 * Function finds number of elements
 * that is in last column in pure
 * output.
 */
int mx_rest(t_files* list, int cols) {
    int rows = 0;
    int rest = 0;

    if (cols == 0)
        cols += 1;

    if(count_files(list) % cols != 0) {
        rows = (count_files(list) / cols) + 1;
        rest = rows - ((rows * cols) - count_files(list));
    }
    if(rows == 1)
        rest = rows;
    if (rows == 0)
        rest = 120;
    return rest;
}

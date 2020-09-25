#include "uls.h"

/* 
 * This is implementation of flag -f 
 * for pure outout.
 * It is function for special case(pure output)
 * it is needed because of difference in outputing
 * architecture 
 * PS.
 * pure output uses array of str.
 * other(-m/-l) use t_files list
 */
void mx_flag_p_for_pureoutput(t_files *list) {
    t_files *tmp = list;

    if (tmp) {
        while(tmp) {
            if (tmp -> type == 'd') {
                char *tmp_name = mx_strjoin(tmp -> file_name, "/");
                free(tmp -> file_name);
                tmp -> file_name = tmp_name;
            }
            tmp = tmp -> next;
        }
    }
}

#include "uls.h"

int *mx_longest_devs(t_files* list, char* directory_name, int* length) {
    t_files* tmp = list;
    char* mode;

    while(tmp) {
        mode = mx_file_mode(tmp -> stats, tmp -> file_name, directory_name);
        if(mode[0] == 'c' || mode[0] == 'b') {
            if(mx_strlen(mx_itoa(MINOR(tmp -> stats.st_rdev))) > length[6])
                length[7] = mx_strlen(mx_itoa(MINOR(tmp -> stats.st_rdev)));
            if(mx_strlen(mx_itoa(MAJOR(tmp -> stats.st_rdev))) > length[7])
                length[6] = mx_strlen(mx_itoa(MAJOR(tmp -> stats.st_rdev)));
            if(length[7] > 3)
                length[7] = 3;
            length[4] = length[6] + length[7] + 2;
        }
        tmp = tmp -> next;
    }
    return length;
}

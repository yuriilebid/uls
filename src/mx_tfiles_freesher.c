#include "uls.h"

// Takes list files and frees.
void mx_tfiles_freesher(t_files *files) {
    if (files) {
        while(files) {
            t_files *tmp = files;
            files = files -> next;
            if (tmp -> file_name)
                free(tmp -> file_name);
            free(tmp);
        }
    }
}

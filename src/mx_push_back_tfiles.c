#include "uls.h"

// Pushes back t_files node in list t_files 
void mx_push_back_tfiles(t_files **list, char *file_name) {
    t_files *node;
    t_files *last_element;

    if (*list == NULL)
        *list = mx_create_tfiles(file_name);
    else { 
        node = mx_create_tfiles(file_name);
        last_element = *list;
        while (last_element -> next != NULL)
            last_element = last_element -> next;
        last_element -> next = node;
    }
}

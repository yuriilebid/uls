#include "uls.h"

// Pushes back t_dirs node in list t_dirs 
void mx_push_back_tdirs(t_dirs **list, char *dir_name) {
    t_dirs *node;
    t_dirs *last_element;

    if (*list == NULL)
        *list = mx_create_tdirs(dir_name);
    else { 
        node = mx_create_tdirs(dir_name);
        last_element = *list;
        while (last_element -> next != NULL)
            last_element = last_element -> next;
        last_element -> next = node;
    }
}

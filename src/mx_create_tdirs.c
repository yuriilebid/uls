#include "uls.h"

// Creates t_dirs list node
t_dirs *mx_create_tdirs(char *dir_name) {
    t_dirs *node = (t_dirs *)malloc(sizeof(t_dirs));
    if (node == NULL) {
        char *msg = "malloc error\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    node -> dir_name = dir_name;
    node -> next = NULL;
    return node;
}

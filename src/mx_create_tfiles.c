#include "uls.h"

// This function creates t_files list node
t_files *mx_create_tfiles(char *file_name) {
    t_files *node = (t_files *)malloc(sizeof(t_files));
    if (node == NULL) {
        char *msg = "malloc error\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    struct stat stats;
    char *f_name;

    if (file_name != NULL) {
        stat(file_name, &stats);
        if(mx_link(file_name, stats))
            lstat(file_name, &stats);
        node->stats = stats;
        node->type = mx_file_type(file_name, stats);  
    }
    f_name = mx_file_name_retriever(file_name);
    if (f_name != NULL) {
        node->file_name = f_name;
        free(file_name);
    }
    else 
        node->file_name = file_name;
    node->next = NULL;
    return node;
}

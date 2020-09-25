#include "uls.h"


/*
 * Function returns int array on the 
 * longest data outputed in flag -l
 * for every type of data
 * (mode, links, user...)
 */
static int* get_each_data_length(t_files* list, char* d, int* l) {
    t_files *tmp = list;

    while(tmp) {
        l = mx_each_l_add(l, tmp, d);
        tmp = tmp -> next;
    }
    return l;
}

static void print_links(t_files *list, char *dir, char *flags) {
    char *path = mx_three_join(dir, "/",list -> file_name);

    if(mx_is_in_arr(flags, 'G'))
        mx_flag_G(list, dir);
    else
        mx_printstr(list -> file_name);
    mx_flag_p(list, flags);
    if(mx_link(path, list -> stats)) {
        mx_printstr(" -> ");
        mx_printstr(mx_link(path, list -> stats));
    }
    else if (list -> type == 'l') {
         mx_printstr(" -> ");
         mx_printstr(mx_link(dir, list -> stats));
    }
    if(list -> next)
        mx_printstr("\n");
    free(path);
}

/*
 * Main function, ouputs flag -l 
 * data and spaces after. To change
 * spaces beetween any type of 
 * output, just change last argument
 * in mx_print_space_after, this is
 * max amount of spaces.
 */
void mx_flag_l_output(t_files *l, char *dir, char *flags) {
    int length_all[9] = {0, 0, 0, 0, 0, 0};
    int length_file[8] = {0, 0, 0, 0, 0, 0};
    
    if(mx_strcmp(l -> file_name, "null") != 0 && l -> type != 'l')
        mx_print_total(l);
    get_each_data_length(l, dir, length_all);
    mx_longest_devs(l, dir, length_all);
    while(l != NULL) {
        mx_flag_l_out_add(l, dir, flags, length_all, length_file);
        print_links(l, dir, flags);
        l = l -> next;
    }
}

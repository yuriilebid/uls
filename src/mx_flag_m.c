#include "uls.h"

// Gets std(terminal) width
static int get_std_width() {
    struct winsize w;
    int width;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;
    return width;
}


// Implementation of flag -m in ls
void mx_flag_m(t_files *files, char *flags, char *dir) {
    t_files *tmp = files;
    int terminal_width = get_std_width();
    int counter = 0;

    if (tmp -> file_name == NULL)
        tmp = tmp -> next;
    while(tmp) {
        if (counter + mx_strlen(tmp -> file_name) + 2 > terminal_width) {
            write(1, "\n", 1);
            counter = 0;
        }
        if(mx_is_in_arr(flags, 'G'))
            mx_flag_G(tmp, dir);
        else
            mx_printstr(tmp -> file_name);
        mx_flag_p(tmp, flags);
        if (tmp -> next != NULL) 
            mx_printstr(", ");
        counter += mx_strlen(tmp -> file_name) + 2; 
        tmp = tmp -> next;
    }
}

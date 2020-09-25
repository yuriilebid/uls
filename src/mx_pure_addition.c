#include "uls.h"

// Function gets terminal width.
static int get_std_width() {
    struct winsize w;
    int width;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;
    return width;
}

/*
 * Function prints spaces after 
 * each printed filename.
 */
static void print_space_after(char* string, int space_size) {
    for(int i = 1; i < space_size - mx_strlen(string); i++)
        mx_printstr(" ");
}

/*
 * Function finds the longest file-
 * name in f_list and returns its 
 * length.
 */
static int long_file(t_files *list) {
    int longest_filename = 0;
    t_files* tmp = list;

    while (tmp) {
        if(tmp->file_name != NULL) {
            if(mx_strlen(tmp->file_name) > longest_filename)
                longest_filename = mx_strlen(tmp->file_name);
        }
        tmp = tmp -> next;
    }
    return longest_filename;
}

/*
 * Function counts the number of 
 * colums in deafult output.
 */
static int mx_cols_count(int width ,t_files *list) {
    int longest = long_file(list);
    int cols = width / ((8 - (longest % 8)) + longest);

    return cols;
}

void mx_pure_addition(t_files *list, char *arr[mx_count_list(list)],
    int cols, int i) {
    int rest = mx_rest(list, cols);
    int space = long_file(list) + (8 - (long_file(list) % 8)) + 1;

    if(arr[i] != NULL) {
        if(cols == 0) {
            mx_printstr("\n");
            rest--;
            cols = mx_cols_count(get_std_width(), list);
            if(rest == 0)
                cols = mx_cols_count(get_std_width(), list) - 1;
        }
        cols--;
        mx_printstr(arr[i]);
        print_space_after(arr[i], space);
    }
}

#include "uls.h"

static char *replace_time_to_year(char* file_time, int file_year) {
    int clock_index = 8;
    char* file_year_string = mx_itoa(file_year);

    for(int j = 0; file_year_string[j]; j++, clock_index++)
        file_time[clock_index] = file_year_string[j];
    file_time[7] = ' ';
    file_time[clock_index] = '\0';
    return file_time;
}

static char *year_change(t_files* list, char* bf, int i, int j) {
    long int file_secs_since_1970 = list->stats.st_mtime;
    long int now_secs_since_1970 = time(NULL);
    int file_year = (file_secs_since_1970 / 31536000) + 1970;
    char *date = mx_strnew(20);
    int spaces = 0;

    while(spaces != 2) {
        date[j] = bf[i];
        if(bf[i] == ':') {
            spaces++;
        }
        i++;
        j++;
    }
    date[j - 1] = '\0';
    if(now_secs_since_1970 - file_secs_since_1970 > 15768000)
        date = replace_time_to_year(date, file_year);
    return date;
}

char *mx_convert_date(char* buff, t_files* list) {
    int index = 0;
    int i = 0;
    char *result;

    while(buff[i] != ' ')
        i++;
    i++;
    result = year_change(list, buff, i, index);
    return result;
}

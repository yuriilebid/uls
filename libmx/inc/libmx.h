#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <string.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/types.h>

char *mx_three_join(char *str1, char *str2, char *str3);
char *mx_strnew(int size);
char *mx_strjoin(char *s1, char *s2);
char *mx_string_copy(char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_copystr(char *str);
char *mx_itoa(int number);
char *mx_link(char *file, struct stat sb);
char **mx_strarr_join(char **arr1, char **arr2);
char **mx_new_strarr(int number_of_str);
void mx_quicksort_strarr(char **arr, int left, int right);
void mx_printstr(const char *s);
void mx_print_strarr(char **strarr);
int mx_is_in_arr(char *s, char c);
int mx_getint_len (int num);
int mx_char_in_arr_counter(char *arr, char c);
int mx_strlen(const char *s);
int mx_strarr_size(char **arr);
int mx_strcmp(const char *s1, const char *s2);

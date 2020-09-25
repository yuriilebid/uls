#include "uls.h"

// Takes user`s id and returns user`s name.
char *mx_getuser(uid_t uid) {
    struct passwd *pws;

    pws = getpwuid(uid);
    return pws->pw_name;
}

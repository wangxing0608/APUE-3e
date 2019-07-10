//
// Created by wangxing on 19-7-10.
//

/*
 * This program is used to list the names of all the files in a directory that
 * is provided as the argument. It is similar to the ls(1) command, but this is
 * a very basic implementation with limited functionality.
 */

#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        err_quit("usage: ls directory_name");
    }

    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s", argv[1]);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
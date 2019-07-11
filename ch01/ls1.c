//
// Created by wangxing on 19-7-10.
//

// 列出一个目录中的所有文件

#include "apue.h"
#include <dirent.h>

// argv[1] 作为要列出其各个目录项的目录名
int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");

    // 该目录无法打开
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);

    // 打印一个目录中所有的文件名
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp ->d_name);

    closedir(dp);
    exit(0);
}
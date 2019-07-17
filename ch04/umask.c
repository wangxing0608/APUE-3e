//
// Created by wangxing on 19-7-17.
//

// umask函数实例

#include "apue.h"
#include <fcntl.h>

#define  RWRRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
    umask(0);
    if (creat("foo", RWRRWRW) < 0)
        err_sys("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRRWRW) < 0)
        err_sys("creat error for bar");
    exit(0);
}

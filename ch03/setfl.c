//
// Created by wangxing on 19-7-16.
//

// 对一个文件标识符设置一个或多个文件状态标志

#include "apue.h"
#include <fcntl.h>

void set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error")

    val |= flags;   // 打开文件标志
    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error")
}

//
// Created by wangxing on 19-7-14.
//

// 创建一个具有空洞的文件

#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;   // 存储文件描述符

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("create error");

    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");  // 当前偏移量为10

    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");

    // 偏移量为16384

    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");

    // 文件偏移量为16394

    exit(0);
}
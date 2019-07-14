//
// Created by wangxing on 19-7-14.
//

// 测试标准输入能否设置偏移量

#include "apue.h"
int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_END) == -1)
    {
        printf("cannot seek\n");
    }
    else
        printf("seek OK\n");
    exit(0);
}
//
// Created by wangxing on 19-7-11.
//

// 输出用户ID组ID

#include "apue.h"

int main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
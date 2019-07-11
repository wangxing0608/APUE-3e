//
// Created by wangxing on 19-7-11.
//

// 1.3 使用C语言中带缓冲区的标准I/O

#include "apue.h"

int main(void)
{
    int c;    //保存输入和输出的字符
    // getc函数一次读取一个字符
    while ((c = getc(stdin)) != EOF)
    {
        // putc函数将此字符写到标准输出
        if (putc(c, stdout) == EOF)
        {
            err_sys("output error");
        }
    }

    if (ferror(stdin))
    {
        err_sys("input error");
    }

    exit(0);
}
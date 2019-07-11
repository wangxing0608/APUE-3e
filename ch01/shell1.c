//
// Created by wangxing on 19-7-11.
//

// 从标准输入读取命令,然后执行这些命令

#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t  pid;   // 保存进程号
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;  // 使用null代替换行符
        }
        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0) {
            // 创创建子进程,并执行
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        // 父进程等待子进程执行结束
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}
//
// Created by wangxing on 19-7-11.
//

//  使用信号处理输入输出

#include "apue.h"
#include <sys/wait.h>

static void sig_int (int);   // 信号捕获函数

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0) {
            // 子进程
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        // 父进程
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%%");
}
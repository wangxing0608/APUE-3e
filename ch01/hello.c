//
// Created by wangxing on 19-7-10.
//

#include "apue.h"

int main(void) {
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}
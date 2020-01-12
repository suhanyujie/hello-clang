#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;
/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_for_simple_error();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    example_for_simple_error();
    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_for_simple_error()
{
    FILE *pf;
    int err_num;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL)
    {
        err_num = errno;
        fprintf(stderr, "错误号：%d\n", errno);
        perror("通过 perror 输出错误\n");
        fprintf(stderr, "打开文件错误:%s\n", strerror(err_num));
    } else {
        fclose(pf);
    }
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*

*/

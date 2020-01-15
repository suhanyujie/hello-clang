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
void example_for_error_with_division_by_0();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_for_simple_error();
    example_for_error_with_division_by_0();
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

// 被 0 除的错误处理
void example_for_error_with_division_by_0()
{
    int dividend = 20;
    int divisor = 0;
    int quotient;
    if (divisor == 0){
        fprintf(stderr, "除数为 0 退出运行...\n");
        exit(-1);
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为：%d\n", quotient);
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 错误处理
* C 语言提供了 perror() 和 strerror() 函数来显示与 errno 相关的文本消息。
    - perror() 函数显示您传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式
    - strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式。
* 下方是一个通过 stderr 文件流来输出所有的错误的简单示例:

```c
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
```

### 被 0 除的错误处理
* c 语言中，我们会手动捕获一些错误，例如下方，当除数为 0 时，我们需要处理这种错误，并将错误输出到错误流 stderr 中。

```c
// 被 0 除的错误处理
void example_for_error_with_division_by_0()
{
    int dividend = 20;
    int divisor = 0;
    int quotient;
    if (divisor == 0){
        fprintf(stderr, "除数为 0 退出运行...\n");
        exit(-1);
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为：%d\n", quotient);
}
```



*/

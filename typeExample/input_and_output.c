#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_print_1();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    example_print_1();

    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
// 输出函数 printf
void example_print_1()
{
    printf("c language learning...\n");
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 输入和输出
* C 语言提供了一系列内置的函数来读取给定的**输入**，并根据需要填充到程序中。
* 同时，C 语言提供了一系列内置的函数来输出数据到计算机屏幕上和保存数据到文本文件或二进制文件中。

### 标准文件
* 在 c 语言中，所有设备都被视为文件。所以，处理设备数据的方式与文件相同。而访问文件最终的元素就是**文件指针**，它是访问文件的方式。
* 常用的 I/O（输入/输出）是 `printf()` 和 `scanf()` 函数。
* `scanf()` 函数用于从标准输入（键盘）读取并格式化；`printf()` 函数发送格式化输出到标准输出（屏幕）。

```
// 输出函数 printf
void example_print_1()
{
    printf("c language learning...\n");
}
```



*/

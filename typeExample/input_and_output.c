#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_print_1();
void example_print_for_putchar();
void example_print_for_getchar();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_print_1();
    //example_print_for_putchar();
    example_print_for_getchar();

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

void example_print_for_putchar()
{
    char str[20] = "hello...\0";
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        putchar(str[i]);
        printf("\t%c\n", str[i]);
    }
    printf("%s, string length is:%d\n", str, len);
}

void example_print_for_getchar()
{
    int c1;
    printf("please enter a value：\n");
    c1 = getchar();
    printf("You entered value is：%d\n", c1);
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

#### putchar 函数
* 输出除了 printf 以外，还有 putchar。该函数把字符输出到屏幕上，并返回相同的字符。需要注意的是，它在同一个时间内只会输出一个单一的字符。
* 与之对应的是 `getchar`

### 输入
#### getchar 函数
* `int getchar(void)` 函数从屏幕读取下一个可用的字符，并把它返回为一个整数(ASCII码值)。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。


*/

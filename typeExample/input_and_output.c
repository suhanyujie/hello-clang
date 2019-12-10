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
void example_print_for_puts_and_gets();
void example_print_for_scanf_and_printf();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_print_1();
    //example_print_for_putchar();
    //example_print_for_getchar();
    //example_print_for_puts_and_gets();
    example_print_for_scanf_and_printf();

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

void example_print_for_puts_and_gets()
{
    char str[100];
    printf("please enter a value:\n");
    gets(str);
    printf("the value is:\n");
    puts(str);
}

// 使用 scanf 和 printf 进行输入输出
void example_print_for_scanf_and_printf()
{
    char str[100];
    int i = 0;
    printf("please enter a value:\n");
    scanf("%s", str);
    printf("the value is:%s\n", str);
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

#### getchar 函数
* `int getchar(void)` 函数从屏幕读取下一个可用的字符，并把它返回为一个整数(ASCII码值)。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

```c
void example_print_for_getchar()
{
    int c1;
    printf("please enter a value：\n");
    c1 = getchar();
    printf("You entered value is：%d\n", c1);
}
```

#### gets 和 puts 函数
* 另一对输入输出函数是 `gets` 和 `puts`。它们的函数原型分别是 `char *gets(char *s)`、`int puts(const char *s) `
* `gets` 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF。
* `puts` 函数把字符串 s 和一个尾随的换行符写入到 stdout 中。
* 注意：在使用 `gets` 的时候，编译器会提示 `warning: this program uses gets(), which is unsafe.`

#### scanf 和 printf 函数
* `int scanf(const char *format, ...)` 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。
* `int printf(const char *format, ...)` 函数把输出写入到标准输出流 stdout ，并根据提供的格式产生输出。 
* 其中 format 参数，可以是一个简单的常量字符串，但是您可以分别指定 `%s`、`%d`、`%c`、`%f` 等来输出或读取字符串、整数、字符或浮点数。
* 示例如下：

```c
// 使用 scanf 和 printf 进行输入输出
void example_print_for_scanf_and_printf()
{
    char str[100];
    int i = 0;
    printf("please enter a value:\n");
    scanf("%s", str);
    printf("the value is:%s\n", str);
}
```

* 需要注意的是  scanf 函数在读取输入时，遇到空格就会停止！因此上方示例程序**无法**输出 `this is a value`，因为其中包含空格。

*/

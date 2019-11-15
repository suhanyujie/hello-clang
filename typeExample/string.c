#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void string_declearation();
void example_strcpy();
void example_strcat();
void example_strcmp();

int main(int argc, char const *argv[])
{
    printf("initial: hello world!\n");
    // string_declearation();
    // example_strcpy();
    example_strcat();
    example_strcmp();


    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
// 字符串声明
void string_declearation()
{
    // 声明方式 1
    char str[] = "hello world";
    printf("%s\n", str);
    // 声明方式 2
    char str2[12] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str2);
    // 可以不需要把 null 字符（'\0'）放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。
    // 因此在声明字符串时，需要额外的一个字符空间存放 null 字符
    char str2_1[12] = {'h', 'e', 'l', 'l', 'o'};
    printf("%s\n", str2_1);
}

// strcpy 示例
void example_strcpy()
{
    char str1[20];
    char str2[20] = "this is a repo";
    printf("%s\n", str1);
    strcpy(str1, str2);
    printf("%s\n", str1);
}

// strcat 示例
void example_strcat()
{
    char str1[20] = "who";
    char str2[4] = "are";
    char str3[4] = "you";
    strcat(str1, str2);
    strcat(str1, str3);
    printf("%s\n", str1);
}

// strcmps 示例
// strcmp 参考 https://www.runoob.com/cprogramming/c-function-strcmp.html
// 如果返回值 < 0，则表示 str1 小于 str2 ；如果返回值 > 0，则表示 str2 小于 str1。
void example_strcmp()
{
    char str1[10] = "hELlo";
    char str2[10] = "hello";
    int res = strcmp(str1, str2);
    printf("the results is:%d\n", res);
}


/*
 -----------------
 | 笔记区
 -----------------
*/
/*

# 字符串
* c 语言中，字符串实际上是一维数组，以字符 '\0' 结尾的一维数组。这里的 '\0' 又被称为 null 字符。


## 字符串操作函数
* 通过引入 `<string.h>` 头文件，我们可以调用很多字符串处理的函数，例如 `strcpy`，`strcat`，`strlen` 等

 */
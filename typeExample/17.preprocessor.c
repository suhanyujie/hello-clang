#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_for_system_defined();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    example_for_system_defined();

    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
// c标准库自带的宏定义使用
void example_for_system_defined()
{
    printf("__FILE__: %s\n", __FILE__);
    printf("__LINE__: %d\n", __LINE__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__: %s\n", __TIME__);
    printf("__STDC__: %d\n", __STDC__);
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 预处理器
* c预处理器简称 `CPP`。c 语言的预处理器不是编译器的组成部分，而是一个单独的部分。它的本质是一个文本替换工具。它主要在实际编译之前指示编译器完成一些预处理。
* 所有的 预处理器命令都是以 `#` 开头，并且是第一个非空字符。
* 预处理器的指令有以下这些：

|指令|描述|
|:-----  |:-----  |
|`#define` |定义宏   | 
|`#include` |包含一个源代码文件   | 
|`#undef` |取消已定义的宏   | 
|`#ifdef` |如果宏已经定义，则返回 true   | 
|`#ifndef` |如果宏没有定义，则返回 true   | 
|`#if` | 如果给定条件为真，额编译跟随其后面的代码   | 
|`#else` | `#if` 的分支   | 
|`#elif` | `#if` 的分支。   | 
|`#endif` | `#if` 的结束。   | 
|`#error` | 当遇到标准错误时，输出错误信息。   | 
|`#pragma` | 使用标准化方法，发布特殊的命令到编译器中。   | 

### 一些实例
* 使用 `#define` 定义常量，注意，后面不能有分号：

```
#define MAX_BUCKET_NUM 20
```

* 使用 `#include` 包含源码文件。
* `#include <stdio.h>` 表示从系统库中获取 stdio.h。
* `#include "myheader.h"` 表示从本地目录中获取 myheader.h。
* 取消，并重新定义宏：

```
#undef MAX_BUCKET_NUM
#define MAX_BUCKET_NUM 10
```

* 先判断，在进行一些操作：

```c
// 如果已经定义 MESSAGE，则重新定义 MESSAGE 为 "you wish!"
#ifndef MESSAGE
    #define MESSAGE "you wish!"
#endif
```

### 系统预定义宏
* c 语言中，已经预定义了很多宏，在编写代码时，可以使用它们。需要注意的是，不能直接修改这些预定义的宏。

|预定义宏|描述|
|:-----  |:-----  |
|`__DATE__` |当前日期，以 "MMM DD YYYY" 格式表示的字符常量。   | 
|`__TIME__` |当前日期，以 "HH:MM:SS" 格式表示的字符常量。   | 
|`__FILE__` |当前的文件名称   | 
|`__LINE__` |当前所处的文件的行号   | 
|`__STDC__` |当编译器以 ANSI 标准编译时，则定义为 1。   | 

* 示例如下：

```c
// c标准库自带的宏定义使用
void example_for_system_defined()
{
    printf("__FILE__: %s\n", __FILE__);
    printf("__LINE__: %d\n", __LINE__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__: %s\n", __TIME__);
    printf("__STDC__: %d\n", __STDC__);
}
```

## 预处理器运算符
### 宏延续运算符


*/

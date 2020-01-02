#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_for_include_once();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");

    example_for_include_once();
    
    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
// 只引用一次
#ifndef HEADER_FILE1
#define HEADER_FILE1
    #include "18.header-file1.h"
#endif
void example_for_include_once()
{
    printf("it will include once...\n");
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 头文件
* 头文件定义：头文件是扩展名为 .h 的文件，包含了 C 函数声明和宏定义，被多个源文件中引用共享。
* 有两种类型的头文件：程序员编写的头文件和编译器自带的头文件。
* 引用头文件相当于复制头文件的内容，但是我们不会直接在源文件中复制头文件的内容，因为这么做很容易出错，特别在程序是由多个源文件组成的时候。
* 在一些如 `A simple practice in C` 的资料中建议把所有的常量、宏、系统全局变量和函数原型写在头文件中，在需要的时候随时引用这些头文件。

### 语法
* 引用头文件需要使用关键字 `define`，其形式如下：

```c
#include <file>
```

* 上方这种，属于引用系统头文件的形式。还有一种引用用户定义的头文件，形式如下：

```c
#include "file"
```

### 只引用一次
* 如果一个头文件被引用两次，编译器会处理两次头文件的内容，这将产生错误。为了防止这种情况，标准的做法是把文件的整个内容放在条件编译语句中，如下：

```c
#ifdef HEADER_FILE
#define HEADER_FILE
    #include "somefile.h"
#endif
```

### 有条件引用
* 又是需要从多个不同的头文件中选择一个引用到程序中。例如，需要指定在不同的操作系统上使用的配置参数。此时可以通过一系列的条件判断来实现：

```
#if SYSTEM_1
    #include "system_1.h"
#elif SYSTEM_2
    #include "system_2.h"
    ...
#endif
```

* 但是如果头文件比较多的时候，这么做是很不妥当的.
*/

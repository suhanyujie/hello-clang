#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/


int main(int argc, char const *argv[])
{
    printf("hello world!");
    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/


/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 共用体
* 共用体是一种特殊的数据类型，它可以允许在相同的内存位置存储不同的数据类型。它规定，我们可以定义一个共用体其中带有多个成员，但是任何时候只能有一个是带有值的。
* 使用关键字 `union` 定义，形式如下：

```c
union [union tag]
{
    member definition1;
    member definition2;
    ...
}[union variable];
```


*/

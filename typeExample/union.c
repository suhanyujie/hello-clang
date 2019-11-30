#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_union_1();
void example_union_2();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    // example_union_1();
    example_union_2();

    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_union_1()
{
    union data {
        int i;
        float f;
        char str[20];
    }data;
    union data d1;
    d1.i = 10;
    printf("%d\n", d1.i);
    d1.f = 3.14;
    printf("%d--%.3f\n", d1.i, d1.f);
}

// 同一时间只使用一个成员变量
void example_union_2()
{
    union data {
        int i;
        float f;
        char str[20];
    }data;
    union data d1;
    d1.i = 10;
    printf("%d\n", d1.i);
    d1.f = 3.14;
    printf("%.3f\n",  d1.f);
}


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

* union 虽然能存储多种类型，但是一次只能存一种。如果强行存多种会发生什么？参考下方示例：

```c
void example_union_1()
{
    union data {
        int i;
        float f;
        char str[20];
    }data;
    union data d1;
    d1.i = 10;
    printf("%d\n", d1.i);
    d1.f = 3.14;
    printf("%d--%.3f\n", d1.i, d1.f);
}
```

* 示例函数运行的结果是 `1078523331--3.140`，可以看出，前一个值已经被破坏了。因为最后赋给变量的值占用了内存位置。
* 我们只要确保在同一时间使用一个变量，就不会出现这个问题：

```c
// 同一时间只使用一个成员变量
void example_union_2()
{
    union data {
        int i;
        float f;
        char str[20];
    }data;
    union data d1;
    d1.i = 10;
    printf("%d\n", d1.i);
    d1.f = 3.14;
    printf("%.3f\n",  d1.f);
}
```

* 此时输出：

```
initial print:hello world!
10
3.140
```


*/

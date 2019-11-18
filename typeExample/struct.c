#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_struct();



int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    example_struct();
    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_struct()
{
    struct Books
    {
        char title[50];
        char author[20];
        float price;
    } book = {"PHP源码剖析", "秦朋", 86.4};

    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 结构体
* 结构体是指：用户自定义的可用的数据类型。它允许您存储不同类型的数据项。
* 定义结构体使用 struct 语句，格式如下：

```c
struct tag {
    member-list
    member-list
    member-list  
    ...
} variable-list ;
```

* tag 是结构体标签。
* member-list 是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。
* variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。其实就是**类型别名**。

### 初始化
* 可以在声明结构体时进行初始化：

```
void example_struct()
{
    struct Books
    {
        char title[50];
        char author[20];
        float price;
    } book = {"PHP源码剖析", "秦朋", 86.4};

    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}
```


*/

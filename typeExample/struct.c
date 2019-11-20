#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_struct();
void example_struct2();
void example_struct3();
void example_struct_include_struct();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    // example_struct();
    // example_struct2();
    example_struct3();

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

// 使用类型别名作为类型声明变量
void example_struct2()
{
    typedef struct Books
    {
        char title[50];
        char author[20];
        float price;
    } Book;

    Book book = {"《细说PHP》", "高洛峰", 45.98};
    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}

// 使用结构体名称方式声明变量
void example_struct3()
{
    struct Books
    {
        char title[50];
        char author[20];
        float price;
    };
    struct Books book = {"《深入浅出Nodejs》", "佚名", 35.98};
    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}

// 结构体中含有结构体
void example_struct_include_struct()
{
    typedef struct Node
    {
        struct Node *prev;
        struct Node *next;
        int data;
    };
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

### 结构体变量的声明
#### 通过别名进行结构体变量声明
* 通过 `typedef` 定义结构体别名，通过别名进行变量声明。

```c
void example_struct2()
{
    typedef struct Books
    {
        char title[50];
        char author[20];
        float price;
    } Book;

    Book book = {"《细说PHP》", "高洛峰", 45.98};
    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}
```

#### 直接通过结构体名称进行变量声明
* 可以直接通过结构体名称进行新的类型变量声明，但这种方式要繁琐一些，需要加上关键字 `struct`

```c
void example_struct3()
{
    struct Books
    {
        char title[50];
        char author[20];
        float price;
    };
    struct Books book = {"《深入浅出Nodejs》", "佚名", 35.98};
    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}
```


*/

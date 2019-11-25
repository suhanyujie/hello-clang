#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_struct();
void example_struct2();
void example_struct3();
void example_struct_include_struct();
void example_include_with_eachother();
void example_struct_initial_1();
void example_struct_initial_2();
void example_struct_pointer();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    // example_struct();
    // example_struct2();
    // example_struct3();
    // example_struct_include_struct();
    // example_include_with_eachother();
    // example_struct_initial_1();
    // example_struct_initial_2();
    example_struct_pointer();

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
    }Node;

    Node* n1;
    Node* n2;
    Node root = {n1, n2, 1};
}

// 结构体互相包含的情况
void example_include_with_eachother()
{
    // 此时需要对其中一个结构体进行**不完整声明**
    struct B;

    struct A
    {
        struct B *b1;
    };
    
    struct B
    {
        struct A *a1;
    };
}

// 结构体变量的初始化 1
void example_struct_initial_1()
{
    struct Books
    {
        char title[50];
        char author[20];
        float price;
    } book = {"PHP源码剖析", "秦朋", 86.4};

    printf("title:%s\n author: %s\n price: %.2f\n", book.title, book.author, book.price);
}

// 结构体变量的初始化 2
// 可以声明好结构体变量后，逐个地对结构体成员赋值
void example_struct_initial_2()
{
    typedef struct Books
    {
        char title[50];
        char author[20];
        float price;
    } Book;
    // Book b1 = {"<低风险创业>", "佚名", 36.8};
    Book *b1 = (Book*)malloc(sizeof(Book));
    strcpy(b1->title, "<低风险创业>");
    strcpy(b1->author, "佚名");
    b1->price = 36.8;
    printf("%s\n", b1->title);
    printf("%s\n", b1->author);
    printf("%.2f\n", b1->price);
}

void example_struct_pointer()
{
    typedef struct Book {
        char title[50];
        char author[30];
    } book;

    book b1;
    strcpy(b1.title, "细说PHP");
    strcpy(b1.author, "高洛峰");
    book *p_b1;
    p_b1 = &b1;

    printf("title is:%s\n", b1.title);
    printf("title is:%s\n", (*p_b1).title);
    printf("title is:%s\n", p_b1->title);
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

### 指向结构体的指针
* 结构体变量的指针和其他类型变量的指针的声明是类似的 `struct Books *p_b1;`，如下示例：

```c
void example_struct_pointer()
{
    typedef struct Book {
        char title[50];
        char author[30];
    } book;

    book b1;
    strcpy(b1.title, "细说PHP");
    strcpy(b1.author, "高洛峰");
    book *p_b1;
    p_b1 = &b1;

    printf("title is:%s\n", b1.title);
    printf("title is:%s\n", (*p_b1).title);
    printf("title is:%s\n", p_b1->title);
}
```

### 位域


*/

#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_tyepdef_1();
void example_print_define_data();

#define true 1
#define false 0
#define BUCKET_NUM 20

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");

    // example_tyepdef_1();
    example_print_define_data();

    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_tyepdef_1()
{
    typedef struct BOOK {
        char title[20];
        float price;
    }Book;

}

void example_print_define_data()
{
    printf("bucket num is:%d\n", BUCKET_NUM);
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## c 语言的 typedef
* c 语言中，可以通过 typedef 关键字为一个类型取一个新的名称。如下给 `unsigned char` 自定义名称：

```c
typedef unsigned char byte;
```

* 自定义一个新的名称后，可以方便的使用：

```c
// 声明变量
byte b1, b2;
```

* 一般会约定使用大写字母开头，如：`Byte`，实际上也能使用小写字母：`byte`

### 给结构体自定义名称
* 在实际使用中，最常见的就是给用户自定义的数据类型命名，也即是给结构体命名：

```c
typedef BOOK {
    ...
}Book;
```

### 和 `#define` 的比较
* 另一个可以对类型重命名的做法是使用 `#define`。但它们之间本质却不相同：
    - typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
    - typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
* 如下是 `#define` 的简单示例：

```c
#define true 1
#define false 0
#define BUCKET_NUM 20
```

*/

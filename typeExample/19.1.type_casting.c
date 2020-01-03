#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_for_simple_transfer();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    example_for_simple_transfer();

    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_for_simple_transfer()
{
    int sum = 17, count = 5;
    double average;
    average = (double)sum / count;
    printf("%.2f\n", average);
}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 强制类型转换
* 类型转换是几乎所有语言都具备的功能，因为它太常用了。
* 强制类型转换是把变量从一种类型转换为另一种数据类型。例如，如果您想存储一个 long 类型的值到一个简单的整型中，您需要把 long 类型强制转换为 int 类型。您可以使用强制类型转换运算符来把值显式地从一种类型转换为另一种类型。形式如下：

```c
(type_name) expression
```

* 下方是一个简单的类型强制转换的示例：

```c
void example_for_simple_transfer()
{
    int sum = 17, count = 5;
    double average;
    average = (double)sum / count;
    printf("%.2f\n", average);
}
```


*/

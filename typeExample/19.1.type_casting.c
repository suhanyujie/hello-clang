#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_for_simple_transfer();
void example_for_integer_imporve_transfer();
void example_for_arithmetic_transfer();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_for_simple_transfer();
    //example_for_integer_imporve_transfer();
    example_for_arithmetic_transfer();

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

// 整数提升
void example_for_integer_imporve_transfer()
{
    int i = 17;
    char c = 'c';
    int sum = 0;
    sum = i + c;
    printf("the result is :%d\n", sum);
}

void example_for_arithmetic_transfer()
{
    int i = 20;
    char c = 'c';// c 字符的 ASCII 值是 `99`
    float sum;
    sum = i + c;
    printf("the result is:%.3f\n", sum);
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

* 上方的例子中，强制转换的优先级大于算术运算符（`/`）的优先级
* 类型转换可以是隐式的，由编译器自动执行，也可以是显式的，通过使用强制类型转换运算符来指定。
* 在编程时，有需要类型转换的时候都用上强制类型转换运算符，是一种良好的编程习惯。

### 整数提升
* 整数提升是指把小于 int 或 unsigned int 的整数转换为 int 或 unsigned int 的过程。如下示例：

```c
// 整数提升
void example_for_integer_imporve_transfer()
{
    int i = 17;
    char c = 'c';
    int sum = 0;
    sum = i + c;
    printf("the result is :%d\n", sum);
}
```

* 运行后，得出的结果值是：116。可见，char 类型的变量 `c` 被提升为 int 类型（对应的 ASCII 值）。

### 常用的算术转换
* 算术转换是指在算术运算过程中隐式的把值强制转换为另一个类型。编译器首先执行整数提升，如果操作数类型不同，则它们会被转换为下列层次中出现的最高层次的类型：

```
long double <- double <- float <- unsigned long long <- long long <- unsigned long <- long <- unsgined int <- int 
```

* 常用的算术转换不适用于赋值运算符、逻辑运算符 —— `&&` 和 `||`。换句话说，就是当执行赋值语句、运算 `&&` 或 `||` 的语句中不会发生隐式转换。

```c
void example_for_arithmetic_transfer()
{
    int i = 20;
    char c = 'c';// c 字符的 ASCII 值是 `99`
    float sum;
    sum = i + c;
    printf("the result is:%.3f\n", sum);
}
```

* 相加得到的值是 `119.000`。代码中，c 先被转换为整数，但由于 sum 的类型是 float，所以会应用常用的算术转换，编译器把 i 和 c 转换为 float，并把它们相加得到一个 float 类型的结果值。

*/

#include <stdio.h>
#include <stdlib.h>

void pointerDeclare();
void pointerDeclare2();
void testPointerOfFunc();
int testPointerOfFunc_ie1(int i, int j);
void populate_array(int *array, size_t arrSize, int (*p)(void));
int getNextRandomValue(void);

int main(int argc, char const *argv[])
{
    // pointerDeclare();
    // pointerDeclare2();
    // testPointerOfFunc();
    // 回调函数示例
    int arr[10];
    populate_array(arr, 10, &getNextRandomValue);
    return 0;
}

void pointerDeclare()
{
    int num1 = 10;
    int *pi;
    double *pf1;
    pi = &num1;

    printf("%p\n", pi);
    printf("num is:%d\n", *pi);
}

void pointerDeclare2()
{
    int num1 = 10;
    int * pi1;
    pi1 = &num1;

    printf("addr is:%p\n", pi1);
    printf("addr after +1 is:%p\n", ++pi1);
    int *pi2;
    pi2 = pi1;
    // 指针的减法
    printf("%p - %p = %d\n", ++pi1, pi2, (pi1 - pi2));// 差值为 1，这里的 1 表示 1 个单位指针
}

int testPointerOfFunc_ie1(int i, int j)
{
    return i + j;
}
void testPointerOfFunc()
{
    int (*p)(int, int) = &testPointerOfFunc_ie1;
    int res = p(2, 3);
    printf("res is %d\n", res);
}

// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextValue();
        printf("the %zuth number is: %d\n", i, array[i]);
    }
}

int getNextRandomValue(void)
{
    return rand();
}

/*
## 指针
* 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。
* 每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。
* 星号  `*` 是用来指定一个变量是指针，如下：

```c
void pointerDeclare()
{
    int num1 = 10;
    int *pi;
    double *pf1;
    pi = &num1;

    printf("%p\n", pi);
    printf("num is:%d\n", *pi);
}
```

* 这里需要注意的是，用来声明指针的星号 `*` 与乘法中使用的星号是相同的。
* 所有实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，对应指针的值的类型都是一样的，都是一个代表内存地址的十六进制数。
* 指针在位于 32 位系统上其大小是 4 字节，而在 16 位系统上是 8 字节。

### C 中的 NULL 指针
* 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
* NULL 指针是一个定义在标准库中的值为零的常量。
* 内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。

### 指针的算术运算
* C 指针是一个用 16 进制数值表示的地址，既然是数值，也就意味着，可以做加减等运算符操作。也因为它可以做一些运算符操作，使其可以非常灵活的运用。
* 例如下方的 ptr 指针：

```c
void pointerDeclare2()
{
    int num1 = 10;
    int * pi1;
    pi1 = &num1;

    printf("addr is:%p\n", pi1);
    printf("addr is:%p\n", ++pi1);
}
```

* 在 **32 位**的整数中，pi1 指针递增一次后，相当于数值增加 4。也就是增加一次，它都将指向下一个整数位置，即当前位置往后移 4 个字节。

## 函数指针
* 我们知道，指针变量是指指向某个变量的指针。那么所谓“函数指针”，就是指向函数的指针了。在实际使用中，我们可以通过指针来实现对函数的调用。

### 函数指针的声明
* 声明原型如下：`typedef int (*fun_ptr)(int,int);`,（声明一个指向同样参数、返回值的函数指针类型），下方是一个简单示例：

```c
int testPointerOfFunc_ie1(int i, int j)
{
    return i + j;
}
void testPointerOfFunc()
{
    int (*p)(int, int) = &testPointerOfFunc_ie1;
    int res = p(2, 3);
    printf("res is %d\n", res);
}
```

* 声明函数指针时，要声明好对应的返回值，参数等类型：`int (*p)(int, int)`，其中一开始的 `int` 是指返回值；后面的 `(int, int)` 则是参数类型 `int`

### 回调函数
* 很多语言中都用“回调函数”的概念，如：JavaScript、PHP等，那么回调函数在底层的 c 是如何实现的呢？下面我们先从介绍回调函数的功能开始。
* 回调函数就是一个通过函数指针调用的函数。例如上方代码示例：

```c
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextValue();
        printf("the %zuth number is: %d\n", i, array[i]);
    }
}
```

* 调用方式是 `populate_array(arr, 10, &getNextRandomValue);`。而 `&getNextRandomValue` 则是对应的函数指针。


*/


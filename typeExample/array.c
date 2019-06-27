#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 初始化二维数组
void initArray2()
{
    int numArr[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24},
    };
    printf("size is:%lu\n", sizeof(numArr)); // 48  12个数，每个数是4字节
}
/**
 * 以下一部分是函数声明
 */ 

void print_average(int arr[],int size);
// 获取随机数
int* getRandom();
void getFirstAddr();
void getFirstAddrPlus();
void getSizeOfPoint();

// 声明数组
void arrDeclaration () {
    int arr[10] = {11,12,85,14,76};
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    // 数组初始化
    // initArray2();
    // int arr1[10];
    // float fArr1[] = {1.0, 2.0, 3.0};
    // // printf("%d\n", arr1);
    // printf("%.2f\n", fArr1[0]);
    // fArr1[2] = 3.14;
    // printf("%.2f\n", fArr1[2]);

    // // 数组参数传递
    // int arr2[3] = {21,89,54};
    // print_average(arr2, 3);

    // 函数返回数组
    // int* res = getRandom();
    // for (size_t i = 0; i < 10; i++)
    // {
    //     printf("the res is : %d\n", res[i]);
    // }
    
    // arrDeclaration();

    // getFirstAddr();
    // getFirstAddrPlus();
    getSizeOfPoint();

    return 0;
}

// 参数是一个数组
void print_average(int arr[],int size)
{
    float average = 0;
    int sum = 0;
    printf("%d\n", sum);
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        printf("%d\n", arr[i]);
    }
    average = (float)sum/size;
    printf("sum is %d,the result is %.2f\n", sum,average);
}

// 要生成返回随机数的函数
int* getRandom()
{
    static int r[10];
    int i;
    // time 返回的类型是 time_t，应该使用 %ld 作为 format 的占位符
    printf("the timestamp is:%ld\n", time(NULL));
    // 给定随机数种子，使用当前时间戳作为种子
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("the num is: %d\n", r[i]);
    }
    
    return r;
}

void getFirstAddr()
{
    int arr[10] = {1,2,3,4};
    int* p1 = arr;
    printf("%d\n", *p1);// 打印的是 arr 的第一个元素的值
    printf("%p\n", p1);
    return;
}

void getFirstAddrPlus()
{
    int arr[10] = {1,2,3,4};
    int* p1 = arr;
    // printf("%p\n", p1);
    p1++;
    printf("%d\n", *p1);
    // printf("%p\n", p1);
    return;
}

void getSizeOfPoint()
{
    int arr[10] = {1,2,3,4};
    int* p1 = arr;
    double* d1;
    // 32 位 CPU 下，指针大小是 4 字节，可以通过：`gcc -m32 -o a.out typeExample/array.c && ./a.out` 查看
    // 64 位 CPU 下，指针大小是 8 字节，可以通过：`gcc -m64 -o a.out typeExample/array.c && ./a.out` 查看
    printf("*int -> %lu\n", sizeof(p1));
    printf("*double-> %lu\n", sizeof(d1));
    return;
}


/*
## 数组
* c语言中的数组，一直是我理解的不是很透彻的东西，如今再次学习巩固一下
* 它是可以存储一个固定大小的相同类型元素的顺序集合。
* 所有的数组都是由连续的内存位置组成。最低的地址对应第一个元素，最高的地址对应最后一个元素。
* 数组中的特定元素可以通过索引访问。比如 numbers，然后使用 numbers[0]、numbers[1]、...、numbers[99] 来代表一个个单独的变量。

### 声明方式
* 它的声明方式如下：`type arrayName [ arraySize ];`，例如：`int arr1[10];double dArr1[6]`
* 这叫做一维数组。arraySize 必须是一个大于零的整数常量，type 可以是任意有效的 C 数据类型。
* `dArr1[6]`的定义中，代表变量`dArr1`可以容纳`6`个元素的数组。

### 初始化
* 声明数组之后，需要对变量初始化，如果不初始化，就使用，编译器会提示warning
* 如果声明时，就初始化，可以不指定数组的长度，类似这样：`float fArr1[] = {1.0,2.0,3.0};`

### 赋值
* 数组的下标是从`0`开始计数，可以通过数组的下标配合进行赋值：`fArr1[2] = 3.14;`
* 数组的最后一个索引是数组的总大小减去 1
* 同样的，数组元素可以通过数组名称加索引（下标）进行访问。`printf("%.2f\n", fArr1[2]);`

### 多维数组
* c语言多维数组的声明方式如下：`type name[size1][size2]...[sizeN];`
* 例如，声明一个整形二维数组：`int numArr[3][4][2];`
* 实际上，在使用过程中，用的做多的可能是`二维数组`

#### 二维数组
* 定义一个二维数组的方式：`type arrayName[x1][x2];`
* `type`是类型名称，`arrayName`是自己取的标识符名称
* 初始化二维数组：

```
int numArr[3][4] = {
    {1,2,3,4},
    {11,12,13,14},
    {21,22,23,24},
};
```

* 使用这种方式也可以初始化：

```
int numArr[3][4] = {1,2,3,4,11,12,13,14,21,22,23,24};
```

* 这种方式和第一种效果是一致的，不过我个人推荐第1中，看起来结构更清晰一些。

#### 访问二维数组元素
* 使用下标，也就是行索引，和列索引

### 传递数组给函数
* 函数调用时，传递一个数组作为参数大致有以下几种：

```
// 种类1 形式参数是一个指针
void myFunction1(int *param){}
// 种类2 形式参数是一个已定义大小的数组
void myFunction2(int param[10]){}
// 种类3 形式参数是一个未定义大小的数组
void myFunction(int param[]){}
```

* 值得注意的是，对函数而言，数组的长度是无关紧要的，因为'C语言'不会对形式参数执行边界检查。

### 从函数返回数组
* c 语言允许从函数返回数组，但它是有条件的：C 语言不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
* 可以查看示例：

```c
int* getRandom()
{
    static int r[10];
    int i;
    printf("the timestamp is:%d\n", time(NULL));
    // 给定随机数种子，使用当前时间戳作为种子
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("the num is: %d\n", r[i]);
    }
    
    return r;
}
```

### 指向数组的指针
* 在 c 语言中，一个数组的数组名代表该数组的起始地址

```c
int arr[10] = {1,2,3,4};
```

* 如上面的代码，arr 就是指向 &arr[0] 的指针。因此，将其赋值，被赋值的变量可以取出对应的值 —— 1
* 还可以对指针进行加减运算，如 `p1++`，它的意义是指向下一个位置的地址：

```c
void getFirstAddrPlus()
{
    int arr[10] = {1,2,3,4};
    int* p1 = arr;
    // printf("%p\n", p1);
    p1++;
    printf("%d\n", *p1);
    // printf("%p\n", p1);
    return;
}
```

* 此时，打印的值是 arr 的第二个元素的值 —— 2



## 参考资料
* http://www.runoob.com/cprogramming/c-arrays.html


*/

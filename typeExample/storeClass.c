#include <stdio.h>

void func1();

// 测试这个例子：`gcc -m32 -o a.out typeExample/storeClass.c typeExample/storeClass2.c&& ./a.out`
extern void testExern();
int iData2 = 2019;
static int iData1 = 0;

int main(int argc, char const *argv[])
{
    int a1 = 0;
    while (a1 < 5)
    {
        func1();
        a1++;
    }
    testExern();

    return 0;
}

void func1()
{
    // 在多次调用`func1`时，`static`修饰的变量`i1`只初始化一次
    static int i1 = 1;
    i1++;
    printf("the result is : %d\n", i1);
}

/*
## 存储类
* 存储类定义 C 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C 程序中可用的存储类：
    * auto
    * register
    * static
    * extern

### auto
*  auto 只能修饰局部变量
* 在普通的声明语句中：`int a = 1;`，实际上默认就是`auto int a = 1;`

### register
* register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
* 定义 'register' 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。

### static
* static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
* static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
* 全局声明的一个 static 变量或方法可以被任何函数或方法调用，只要这些方法出现在跟 static 变量或方法同一个文件中。

### extern
* extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
* 当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。
* 也就是说，`extern`修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候

*/

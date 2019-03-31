#include <stdio.h>
#include <float.h>

void varia_statement();

int main(int argc, char const *argv[])
{
    varia_statement();
    return 0;
}

// 变量的声明
void varia_statement()
{
    //extern int i2;
    int i1 = 1;
    printf("%d",i1);
}

// 打印浮点数
void fmt_float()
{
    int i1 = 12;
    void *s1 = &i1;
    printf("%.2f\n", *(float *)++s1);
    // 打印最小浮点数
    printf("%E\n", FLT_MIN);
}

/**
 *
## 变量
* char 占1个字节
* int 占4个字节
* float 占4个字节
* double 占8个字节
* void 表示类型缺失

### 变量的定义
* 定义格式如下：`type variable_list`
* 其中type，表示类型名称，例如：`int i1,i2;`
* 在定义变量的时候，可以直接初始化，格式：`type variable_name = value;`
* 例如：`int i1 = 12;`

### 变量的声明
* c语言中，变量的声明是指：向编译器保证变量以指定的类型和名称存在
* 变量的声明有两种情况：
>1、一种是需要建立存储空间的。例如：int a 在声明的时候就已经建立了存储空间<br>
2、另一种是不需要建立存储空间的，通过使用extern关键字声明变量名而不定义它。 例如：extern int a 其中变量 a 可以在别的文件中定义的。

* 除非有extern关键字，否则都是变量的定义
* 因此，`变量的定义` 和 `变量的声明` 是有区别的

## 左值和右值
* C 中有两种类型的表达式：
    * 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
    * 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。
* 变量是左值，因为它可以出现在赋值号的左边
* 数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。




## 参考资料
* http://www.runoob.com/cprogramming

 * 
 */

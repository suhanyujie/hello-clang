#include <stdio.h>

// 函数声明在main之后的，需要预定义！
void constDefine();

int main(int argc, char const *argv[])
{
    constDefine();
    return 0;
}

void constDefine(){
    const int I1 = 123;
    printf("%d\n", I1);
}


/**
 * 
## 常量
* 常量包括以下几种类型：

### 整数常量
* 整数常量中，又包括：十进制、8进制、16进制的整数常量

### 浮点数常量
* 浮点常量由整数部分、小数点、小数部分和指数部分组成
* 如：`314159E-5L`

### 字符常量
* 字符常量是括在单引号中，例如，'x' 可以存储在 char 类型的简单变量中。
* 还包括一些特殊字符：`\\`,`\'`..

### 字符串常量
* 字符串字面值或常量是括在双引号 "" 中的
* 如:"hello world",...

### 自定义常量
* C语言中，有2中定义常量的方式
    * 使用`#define`预处理器，格式形如：`#define identifier value`
    * 使用`const`关键字定义常量，格式形如：`const type variable = value;`






 * 
 */ 

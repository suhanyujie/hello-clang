#include <stdio.h>

// 函数声明
int funcNameExample(){
    return 2019;
}

int main(int argc, char const *argv[])
{
    printf("the result is:%d\n", funcNameExample());
    return 0;
}

/*
## 函数
* 和大部分的函数一样，格式如下：

```c
return_type function_name( parameter list )
{
   body of the function
}
```

* 其中`return_type`代表返回值类型，`function_name`是函数名称
* 括号中是形参列表
* 形参定义：形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁。
* c语言中，函数调用时参数传递的2种方式：

### 传值调用
* 该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。

### 引用调用
* 通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。


*/

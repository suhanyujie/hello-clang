#include <stdio.h>

enum WEEK 
{
    MON=1,
    TUE,
    WEN,
    THU,
    FRI,
    SAT,
    SUN,
};

enum ENUM_NOT_FIRST
{
    NF_1,
    NF_2,
    NF_3,
};

enum ENUM_THIRD{
    TH_1,
    TH_2,
    TH_3,
    TH_4 = 19,
    TH_5,
    TH_6,
};

int main(int argc, char const *argv[])
{
    printf("WEEK -> %d\n", TUE);
    printf("ENUM_NOT_FIRST -> %d\n", NF_1);
    printf("ENUM_THIRD TH_1 -> %d\n", TH_1);
    printf("ENUM_THIRD TH_5 -> %d\n", TH_5);
    return 0;
}

/*
## 枚举
* 枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读。
* C 语言中，枚举的定义方式如下：`enum 枚举名 {枚举元素1, 枚举元素2, 枚举元素3, ...}`
* 另外，枚举声明的括号后需要加 `;`，最后一个元素后也能有逗号。
* 例如下方的使用星期作为枚举元素的枚举类型：

```c
enum WEEK 
{
    MON=1,
    TUE,
    WEN,
    THU,
    FRI,
    SAT,
    SUN,
}
```
### 枚举的第一个元素指定值
* 如上方所示，第一个枚举成员的默认值为整型的 1，后续枚举成员的值在前一个成员上加 1。

### 枚举的第一个元素未指定值
* 如果第一个元素没有指定值，则其值默认为 `0`。后续的值分别是前一个值加 1。
* 例如上方示例：

```c
enum ENUM_NOT_FIRST
{
    NF_1,
    NF_2,
    NF_3,
};
```


### 中间某元素指定值
* 当枚举非第一个元素指定值，那么后续的值就是从这个值开始递增。而该元素之前的值是从 0 开始递增的。如下示例：

```c
enum ENUM_THIRD{
    TH_1,
    TH_2,
    TH_3,
    TH_4 = 19,
    TH_5,
    TH_6,
};
```



*/

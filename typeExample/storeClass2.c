#include <stdio.h>

// 此处用extern的作用是：得到在其他文件中已定义的变量或函数的引用
extern int iData2;

void testExern() {
    printf("this is test for extern(%d)...\n", iData2);
}

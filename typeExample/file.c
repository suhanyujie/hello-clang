#include <stdio.h>
#include <stdlib.h>

/*
 -----------------
 | 函数声明区
 -----------------
*/
void example_fopen();
void example_fputc();
void example_fputs();


int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_fopen();
    example_fputc();
    return 0;
}

/*
 -----------------
 | 函数实现区
 -----------------
*/
void example_fopen()
{
    char str[100];
    size_t len = 100;
    FILE *f1 = fopen("./README.md", "r");
    printf("%s\n", fgetln(f1, &len));
    fclose(f1);
}

void example_fputc()
{
    char str[20];
    FILE *f1 = fopen("./tmp_data.txt", "a");
    char c1 = fputc(97, f1);
    printf("%c\n", c1);
    fclose(f1);
}

void example_fputs()
{

}

/*
 -----------------
 | 笔记区
 -----------------
*/
/*
## 文件读写
### 打开文件
* c 语言中，可以使用 `fopen` 函数来创建一个新的文件或者打开一个已有的文件，这个调用会初始化类型 FILE 的一个对象，类型 FILE 包含了所有用来控制流的必要的信息。
* `fopen` 函数原型如下：

```c
FILE *fopen( const char * filename, const char * mode );
```

* 其中 mode 值如下：
    - r	打开一个已有的文本文件，允许读取文件。
    - w	打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。如果文件存在，则该会被截断为零长度，重新写入。
    - a	打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。
    - r+	打开一个文本文件，允许读写文件。
    - w+	打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
    - a+	打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。
 * 如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：   
>"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"

* fopen 的使用示例如下：

```c
void example_fopen()
{
    char str[100];
    size_t len = 100;
    FILE *f1 = fopen("./README.md", "r");
    printf("%s\n", fgetln(f1, &len));
    fclose(f1);
}
```
### 写入文件
* `fputc` 函数是最简单的函数，其原型如下：

```
int fputc( int c, FILE *fp );
```

* 它的作用是把 c 字符值写入 `fp` 所指向的输出流中。如果写入成功，它会返回写入的字符，发生错误，则返回 EOF。
* `fputc` 只能写入单个字符，并且是 ASCII 值的方式写入。如果要写入字符串，该怎么办呢？
* 写入字符串可以使用 `fputs`：`int fputs( const char *s, FILE *fp );`
* 函数 `fputs` 把字符串 s 写到 fp 所指向的输出流中。成功，返回一个非负值，否则返回 EOF。示例代码如下：

```c
void example_fputc()
{
    char str[20];
    FILE *f1 = fopen("./tmp_data.txt", "a");
    char c1 = fputc(97, f1);
    printf("%c\n", c1);
    fclose(f1);
}
```



### 读取文件

### 二进制 I/O 函数





*/

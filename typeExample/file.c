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
void example_read_file();
void example_fread_and_fwrite();

int main(int argc, char const *argv[])
{
    printf("initial print:hello world!\n");
    //example_fopen();
    //example_fputc();
    //example_fputs();
    //example_read_file();
    example_fread_and_fwrite();
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

// 通过 fputs 向文件中写入字符串
void example_fputs()
{
    char str[20];
    FILE *f1 = fopen("./tmp_data.txt", "a");
    char c1 = fputs("this is a string\n", f1);
    printf("%c\n", c1);
    fclose(f1);
}

// 读取文件内容
void example_read_file()
{
    char str[20];
    char buf[255];
    int c1 = 0;
    FILE *f1 = fopen("./tmp_data.txt", "r");
    // 使用 fgetc 读取文件
    for (size_t i = 0; i < 5; i++)
    {
        c1 = fgetc(f1);
        printf("the one char is:%c\t", c1);
    }
    printf("\n");
    // 使用 fgets 读取文件。遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符
    fgets(buf, 255, f1);
    printf("fgets get content is:%s\n", buf);
    // 使用 fscanf 读取文件。遇到空格或换行，则停止读取
    fscanf(f1, "%s", buf);
    printf("fscanf get content is:%s\n", buf);
    fclose(f1);
}

void example_fread_and_fwrite()
{
    char str[20] = "\0";
    // fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
    FILE *f1 = fopen("./tmp_data.txt", "a");
    size_t num_write = 0;
    num_write = fwrite(str, sizeof(char), 8, f1);
    fclose(f1);
    
    f1 = fopen("./tmp_data.txt", "r");
    size_t num1 = fread(str, sizeof(char), 8, f1);
    printf("%s\t%zu\t%zu\n", str, num_write, num1);
    fclose(f1);
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

// 通过 fputs 向文件中写入字符串
void example_fputs()
{
     char str[20];
    FILE *f1 = fopen("./tmp_data.txt", "a");
    char c1 = fputs("this is a string\n", f1);
    printf("%c\n", c1);
    fclose(f1);
}
```

### 读取文件
* 与 putc/puts 相对的是读取文件的  fgetc/fgets。
* `fgetc()` 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。
* 函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。
* 除此之外，也可以使用 `int fscanf(FILE *fp, const char *format, ...)` 函数来从文件中读取字符串，但是在遇到第一个空格和换行符时，它会停止读取。
* 示例代码如下：

```c
// 读取文件内容
void example_read_file()
{
    char str[20];
    char buf[255];
    int c1 = 0;
    FILE *f1 = fopen("./tmp_data.txt", "r");
    // 使用 fgetc 读取文件
    for (size_t i = 0; i < 5; i++)
    {
        c1 = fgetc(f1);
        printf("the one char is:%c\t", c1);
    }
    printf("\n");
    // 使用 fgets 读取文件。遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符
    fgets(buf, 255, f1);
    printf("fgets get content is:%s\n", buf);
    // 使用 fscanf 读取文件。遇到空格或换行，则停止读取
    fscanf(f1, "%s", buf);
    printf("fscanf get content is:%s\n", buf);
    fclose(f1);
}
```

### 二进制 I/O 函数
* c 语言中，这两个函数用于二进制的输入输出：

```c
size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
```

* 通常用于存储块的读写（数组或结构体的读写）。示例如下：

```c
void example_fread_and_fwrite()
{
    char str[20] = "\0";
    // fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
    FILE *f1 = fopen("./tmp_data.txt", "a");
    size_t num_write = 0;
    num_write = fwrite(str, sizeof(char), 8, f1);
    fclose(f1);
    
    f1 = fopen("./tmp_data.txt", "r");
    size_t num1 = fread(str, sizeof(char), 8, f1);
    printf("%s\t%zu\t%zu\n", str, num_write, num1);
    fclose(f1);
}
```

* 需要注意的是，读文件时使用的 mode 为 `r`。而写文件时，使用的是 `w`/`a`。如果用的不对，会出现读不出数据的情况。

## 参考
* http://c.biancheng.net/view/2071.html

*/

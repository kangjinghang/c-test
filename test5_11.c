#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

#define MAX_VALUE 100
#define reg register
#define STR "hehe"
#define do_forever for (;;)
#define SQUARE(X) (X) * (X)
#define DOUBLE(X) ((X) + (X))
#define PRINT(X) printf("the value of " #X " is %d\n", X);
#define CAT(X, Y) X##Y
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define SIZEOF(type) sizeof(type)
#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
#define DEBUG 0

struct S
{
    char c1;
    int aa;
    char c2;
};

#define OFFSETOF(struct_name, member_name) (int)&(((struct_name *)0)->member_name)

int main()
{
    int i = MAX_VALUE;
    int arr[10] = {0};
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    // 呵呵
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    // 哈哈
    printf("\n");
    // 预定义符号
    printf("%s\n", __FILE__); // test5_11.c，代码所在文件
    printf("%d\n", __LINE__); // 28，代码所在行号

    printf("%s\n", __DATE__); // Mar 23 2022
    printf("%s\n", __TIME__); // 00:25:56

    // 预处理指令，#开头的，比如：
    // #include
    // #define
    // #pragma pack(4)
    // #pragma
    // #if
    // #endif
    // #ifend
    // #line
    // ...

    //  一步到位：gcc test5_11.c -o test5_11

    // 预编译/预处理阶段：gcc -E test5_11.c > test5_11.i，生成了 .i 文件
    // 1.#include 头文件的包含
    // 2.注释删除：使用空格替换注释
    // 3.#define
    // 综上，预处理阶段都是文本操作

    // 编译阶段：gcc -S test5_11.i，生成了 test5_11.s 文件
    // 把C代码翻译成汇编代码：语法分析、词法分析、语义分析、符号汇总

    // 汇编阶段：gcc -c test5_11.s，生成了 test5_11.o 文件
    // 把汇编代码转换成了二进制指令
    // 形成符号表

    // 链接阶段
    // 1.合并段表 2.符号表的合并和符号表的重定位

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // int ret = SQUARE(5);
    // 宏的参数不是传参的，而是替换的
    // SQUARE(5 + 1) = 5 + 1 * 5 + 1 = 5 + 5 + 1 = 11
    // 所以，要加上括号 X *X -> (X) * (X)
    int ret = SQUARE(5 + 1); // 11
    printf("%d\n", ret);

    int a = 5;
    // DOUBLE(X) X + X
    // ret = 10* a + a = 55
    // 所以，要加上括号 X + X ->  ((X) + (X))
    ret = 10 * DOUBLE(a); // 100
    printf("%d\n", ret);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    PRINT(a);
    int Class84 = 2019;
    printf("%d\n", CAT(Class, 84));
    // 等价于：printf("%d\n", Class##84);
    // 等价于：printf("%d\n", Class84);
    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 带副作用的宏参数
    a = 10;
    int b = 11;
    int m = MAX(a++, b++);
    // 带副作用了，int m = (a++) > (b++) ? (a++) : (b++)
    // int m = 10 > 11 为false，a = 11，b=12
    // 返回 b++，即 m = 12，b再加1 = 12+1=13
    printf("%d\n", m); // 12
    printf("%d\n", a); // 11
    printf("%d\n", b); // 13

    // 函数与宏的对比
    // 函数在调用的时候会有函数调用和返回的开销
    // 而宏在预处理阶段就完成了替换，没有函数调用和返回的开销
    // 宏的规模和速度相对更高一些，而且宏是与类型无关的，而函数必须声明为特定类型
    // 但是，宏也有它的劣势：
    // 1.宏替换可能使程序的长度大幅增加
    // 2.宏是没法调试的
    // 3.宏与类型无关，也就不够严谨
    // 4.宏可能会带来运算符优先级的问题，导致更容易出错

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 宏有时能做到函数无法做到的事，比如宏的参数可以传 “类型” 进去
    ret = SIZEOF(int);
    printf("%d\n", ret); // 4

    // 更加方便
    int *p = MALLOC(10, int);
    printf("%p\n", p);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 条件编译
    // 1.
    // #if 常量表达式
    //      ....
    // #enif

    // 2.多个分支的条件编译
    // #if 常量表达式
    //      ....
    // #elif 常量表达式
    //      ....
    // #else
    //      ....
    // #endif

// #if 1 == 1
#if 1 == 2
    printf("haha\n");
// #elif 1 == 2
#elif 2 == 2
    printf("hehe\n");
#else
    printf("heihei\n");
#endif

    // 3.判断是否被定义
    // #if defined(symbol)
    // #ifdef symbol
#if defined(DEBUG)
    // 加上 #define DEBUG 0 ，就会生效，打印下面的语句
    printf("haha\n");
#endif
#ifdef DEBUG
    printf("haha\n");
#endif
    // 相反的：
    // #if !defined(symbol)
    // #ifndef symbol

    // 4.嵌套指令

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 文件包含
    // #include "filename" 先在当前目录查找，然后查找标准库目录查找。效率低一些
    // #include <filename> 只在标准库目录查找

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 解决嵌套的引入头文件，答案是：条件编译
    // 要改头文件，比如头文件是 test.h
    // #ifndef __TEST_H__
    // #define __TEST_H__
    // ...
    // #endif
    // 解决头文件的重复引入问题
    // 第二种写法：
    // #pragma onc
    // 这是比较新的写法，第一种是比较传统的写法

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    // 编写宏，计算结构体中某变量相对于首地址的偏移
    printf("%lu\n", OFFSETOF(struct S, c1)); // 0
    printf("%lu\n", OFFSETOF(struct S, aa)); // 4
    printf("%lu\n", OFFSETOF(struct S, c2)); // 8
}
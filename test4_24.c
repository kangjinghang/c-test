#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

// 位段：二进制位
struct S
{
    int a : 2; // 2 bit
    int b : 5;
    int c : 10;
    int d : 30;
    // 47bit
};

struct S2
{
    char a : 3; // 3 bit
    char b : 4;
    char c : 5;
    char d : 4;
    // 16bit
};

union Un
{
    char c;
    int i;
};

union Unx
{
    int a;       // 4，对齐数是4
    char arr[5]; // 5，用元素的对齐数作为数组的对齐数，就是1
};

// 检测是大端还是小端排序
int check_sys()
{
    union
    {
        char c;
        int i;
    } u;
    u.i = 1;
    // 返回1表示小端，0表示大端
    return u.c;
}

int main()
{
    // 位段的声明和结构是类似的，有两个不同：
    // 1.位段的成员必须是 int 、unsigned int 、signed int 、short 、char ...
    // 2.位段的成员后边有一个冒号和一个数字。
    struct S s;
    printf("%lu\n", sizeof(s)); // 8个字节

    // 位段的内存分配
    // 1.位段的成员可以是 int 、unsigned int 、signed int 、char 等整型家族类型
    // 2.位段的空间上按照需要以4个字节（int）或者1个字节（char）的方式来开辟的
    // 3.位段涉及很多不确定因素，位段是不跨平台的，注重可移植性的程序应该避免使用位段

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    struct S2 s2;
    s2.a = 10; // 0b10[10] 先使用低位，多出来的浪费掉
    s2.b = 20; // 0b1[0100]
    s2.c = 3;
    s2.d = 4;
    printf("%lu\n", sizeof(s2)); // 3个字节

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    union Un u;
    // 联合体是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小
    printf("%lu\n", sizeof(u)); // 4
    printf("%p\n", &u);         // 0x7ff7b1041090
    printf("%p\n", &(u.c));     // 0x7ff7b1041090
    printf("%p\n", &(u.i));     // 0x7ff7b1041090

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 大端 or 小端
    // 低地址---------------->高地址
    // ...[][][][11][22][33][44][][][][]... 大端字节序存储模式
    // ...[][][][44][33][22][11][][][][]... 小端字节序存储模式

    int check_ret = check_sys();
    if (check_ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    // 联合体大小的计算：
    // 1.联合体的大小至少是最大成员的大小
    // 2.当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍

    union Unx ux;
    // 联合体是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小
    printf("%lu\n", sizeof(ux)); // 8

    return 0;
}
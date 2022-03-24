#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

struct Stu
{
    char name[20];
    char tele[12];
    char sex[10];
    int age;
} s3, s4, s5; // 全局变量

// 匿名结构体类型
struct
{
    int a;
    char b;
    float c;
} x;

struct
{
    int a;
    char c;
} sa;

struct
{
    int a;
    char c;
} * psa;

// struct Node
// {
//     int data;
//     struct Node *next;
// };

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

struct S1
{
    char c1; // 偏移量：0，对齐数：1
    int a;   // 偏移量：4，对齐数：4
    char c2; // 偏移量：8，对齐数：1
    // 8 + 1 = 9 ，所有成员变量最大对齐数是4，所以整体占用空间大小对齐到12
};

struct S2
{
    char c1; // 偏移量：0，对齐数：1
    char c2; // 偏移量：1，对齐数：1
    int a;   // 偏移量：4，对齐数：4
    // 4 + 4= 8 ，所有成员变量最大对齐数是4，所以整体占用空间大小对齐到8
};

struct S3
{
    double d; // 偏移量：0，对齐数：8
    char c;   // 偏移量：8，对齐数：1
    int i;    // 偏移量：12，对齐数：4
    // 12 + 4= 16 ，所有成员变量最大对齐数是8，所以整体占用空间大小对齐到16
};

// 嵌套结构体
struct S4
{
    char c1;       // 偏移量：0，对齐数：1
    struct S3 s33; // 偏移量：8，对齐数：8，大小16个字节
    double d;      // 偏移量：24，对齐数：8
    // 24 + 8= 32 ，所有成员变量最大对齐数是8，所以整体占用空间大小对齐到32
};

#pragma pack(4) // 设置默认对齐数为4
// #pragma pack()  // 取消默认的对齐数
struct S
{
    char c1;  // 偏移量：0，对齐数：1
    double d; // 偏移量：8，对齐数：8，大小16个字节。设置默认对齐数为4后，偏移量：4，对齐数：4
    // 8 + 8= 16 ，所有成员变量最大对齐数是8，所以整体占用空间大小对齐到16
};

void initS(struct S *ps)
{
    ps->c1 = 'w';
    ps->d = 2.0;
}

void printS(struct S s)
{
    printf("%c %f\n", s.c1, s.d);
}

void print2S(struct S *ps)
{
    printf("%c %f\n", ps->c1, ps->d);
}

int main()
{
    // 局部变量
    struct Stu s1;
    struct Stu s2;

    // psa = &sa; // 警告，这两个类型是不一样的，虽然成员变量完全相同

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    Node n1;

    // 如何计算结构体的大小？首先要掌握结构体的对齐规则
    // 1.第一个成员在结构体变量偏移量为0的地址处
    // 2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
    // 对齐数：编译器默认的一个对齐数 与 该成员变量大小的 较小值
    // vs中默认的值为8
    // 3.结构体的总大小为最大对齐数（每个成员变量都一个对齐数）的整数倍。
    // 4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的
    // 整体大小就是所有最大对齐数（包含嵌套结构体的对齐数）的整数倍。
    struct S1 s11 = {0};
    printf("%lu\n", sizeof(s11)); // 12
    struct S2 s21 = {0};
    printf("%lu\n", sizeof(s21)); // 8
    struct S3 s31 = {0};
    printf("%lu\n", sizeof(s31)); // 16
    struct S4 s41 = {0};
    printf("%lu\n", sizeof(s41)); // 32

    // 为什么存在内存对齐？
    // 1.平台原因，某些平台只能在某些地址取某些特定类型的数据，否则抛出硬件异常
    // 2.性能原因，为了访问未对齐的内存，处理器需要做两次内存访问，而对齐的内存仅需要一次访问
    // 总体来说，是 空间换时间 的说法。

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    struct S s = {0};
    printf("%lu\n", sizeof(s));              // 16
    printf("%lu\n", offsetof(struct S, c1)); // 0，得到成员相对结构体的偏移量
    printf("%lu\n", offsetof(struct S, d));  // 4，得到成员相对结构体的偏移量

    // 初始化结构体变量，传入指针即可
    initS(&s);
    printS(s);   // 传值
    print2S(&s); // 传址，这种较好，节省压栈的时候的系统开销

    return 0;
}
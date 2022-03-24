#include <stdio.h>
#include <string.h>

struct Book
{
    char name[20]; // C语言程序设计
    short price;   // 55
};

int main()
{
    int a = 10;
    printf("%p\n", &a);
    int *p = &a;
    printf("%p\n", p);

    // 利用结构体类型创建一个该类型的结构体变量
    struct Book b1 = {"C语言程序设计", 55};
    printf("书名:%s\n", b1.name);
    printf("价格:%d元\n", b1.price);
    b1.price = 15;
    printf("修改后的价格:%d元\n", b1.price);

    printf("--------------------\n");

    struct Book *pb = &b1;
    // 利用pb打印书名和价格
    // .    结构体变量.成员
    printf("书名:%s\n", (*pb).name);
    printf("价格:%d元\n", (*pb).price);

    printf("--------------------\n");
    // ->    结构体指针->成员
    printf("书名:%s\n", pb->name);
    printf("价格:%d元\n", pb->price);

    printf("--------------------\n");
    // name是数组，是个地址，不能像price一样用变量简单的赋值，所以要用strcpy函数
    strcpy(b1.name, "C++");
    printf("书名:%s\n", b1.name);

    return 0;
}
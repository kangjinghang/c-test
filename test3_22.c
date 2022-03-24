#include <stdio.h>

int *test()
{
    // 局部变量，函数结束后内存销毁，返回的指针指向的内存空间是错误的
    int a = 10;
    return &a;
}

int main()
{
    printf("%ld\n", sizeof(char *));
    printf("%ld\n", sizeof(short *));
    printf("%ld\n", sizeof(int *));
    printf("%ld\n", sizeof(double *));
    int a = 0x1122334;
    int *pa = &a;
    char *pc = &a;
    // 1. 指针类型决定了解引用操作的时候，能够访问空间的大小
    // *pa = 0; // 改了4个字节 00 00 00 00
    // *pc = 0; // 改了1个字节 00
    printf("%p\n", pa); // 0x7ff7bf90d0ac
    printf("%p\n", pc); // 0x7ff7bf90d0ac

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 2.指针类型决定了指针走一步走多远，就是决定了指针的步长
    // int    *p : p+1 -> 4
    // char   *p : p+1 -> 1
    // double *p : p+1 -> 8
    printf("%p\n", pa + 1); // 0x7ff7bf90d0b0 = 0x7ff7bf90d0ac + 4byte
    printf("%p\n", pc + 1); // 0x7ff7bf90d0ad = 0x7ff7bf90d0ac + 1byte

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int arr[10] = {0};
    int *p = arr; // arr数组名,首元素的地址

    for (int i = 0; i < 10; i++)
    {
        *(p + i) = 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int *p2 = test();
    printf("%p\n", p2); // 野指针
    // 正确做法，不知道指针指向哪里或者要释放的时候
    *p2 = NULL;
}
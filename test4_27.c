#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

struct S
{
    int n;
    int arr[]; // 未知大小的
};

int main()
{
    // 向内存申请10个整型的空间
    int *p = (int *)malloc(10 * sizeof(int));
    // int *p = (int *)malloc(INT64_MAX);
    if (p == NULL)
    {
        // 打印错误
        printf("%s\n", strerror(errno)); // Cannot allocate memory
    }
    else
    {
        // 正常使用
        for (int i = 0; i < 10; i++)
        {
            *(p + i) = i;
            printf("%d ", *(p + i));
        }
    }

    // 当空间不再使用的时候应该还给操作系统
    // 需要是动态开辟 （malloc 等函数） 的空间才需要free，数组不需要
    free(p);
    p = NULL; // 断开连接

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节都初始化为 0
    int *cp = calloc(10, sizeof(int));

    if (cp == NULL)
    {
        // 打印错误
        printf("%s\n", strerror(errno)); // Cannot allocate memory
    }
    else
    {
        // 正常使用
        for (int i = 0; i < 10; i++)
        {
            *(cp + i) = i;
            printf("%d ", *(cp + i));
        }
    }

    // free 函数是用来释放动态开辟的空间的
    free(cp);
    cp = NULL; // 断开连接

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int *p1 = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        *(p1 + i) = i;
    }

    // 假设40个字节不能满足我们的使用要求，我们希望有80个字节空间，可以使用realloc来调整动态开辟的空间
    int *rp = realloc(p1, 40);

    for (int i = 10; i < 20; i++)
    {
        *(rp + i) = i;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", *(rp + i));
    }
    free(rp);
    rp = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 错误示例：
    // 1.对 NULL 进行解引用操作
    // 2.对动态开辟的内存进行越界访问
    // 3.对非动态开辟的内存的 free
    // 4.使用 free 释放动态开辟内存的一部分
    // 5.对同一块动态开辟的内存的多次释放
    // 6.对动态开辟的内存忘记释放（内存泄漏）

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 柔性数组
    struct S s;
    printf("%lu\n", sizeof(s));

    // 4 + 5 * 4 = 20 ，4  + 20 = int + arr[]
    struct S *ps = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
    ps->n = 100;
    for (int i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    printf("\n");

    struct S *pps = realloc(ps, 44);
    if (pps != NULL)
    {
        ps = pps;
    }

    for (int i = 0; i < 10; i++)
    {
        ps->arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    free(ps);
    ps = NULL;
    printf("\n");

    return 0;
}
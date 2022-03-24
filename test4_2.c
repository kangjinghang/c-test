#include <stdio.h>
#include <string.h>

int main()
{
    char arr[] = "abcde";
    char *pc = arr;
    printf("%s\n", arr);
    printf("%s\n", pc);

    // "abcdf" 是一个常量字符串，p存放的是首字符'a'的地址
    const char *p = "abcdf";
    // *p = 'w';
    printf("%s\n", p); // 从'a'的地址开始打印字符串，直到'\0'
    printf("%c\n", *p);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char arr1[] = "abcdef";
    char arr2[] = "abcdef";
    const char *p1 = "abcdef"; // 常量字符串，不能被修改，指向同一个地址空间
    const char *p2 = "abcdef";
    if (p1 == p2)
    {
        printf("hehe\n");
    }
    else
    {
        printf("haha\n");
    }

    // 存放整形指针的数组
    int *parr[4];

    int iarr1 = {1, 2, 3, 4, 5};
    int iarr2 = {2, 3, 4, 5, 6};
    int iarr3 = {3, 4, 5, 6, 7};
    int *piarr = {&iarr1, &iarr2, &iarr3};

    // p就是数组指针，[]结合性比*高，所以要加上()
    int(*pp)[5] = &iarr1;
    for (int y = 0; y < 5; y++)
    {
        // printf("%d ", (*p1)[y]);
        printf("%d ", *(*pp + y)); // *pp = iarr1
    }

    // int *px = iarr2;
    // for (int y = 0; y < 5; y++)
    // {
    //     printf("%d ", px[y]);
    //     printf("%d ", *(px + y));
    //     printf("%d ", *(arr2 + y));
    //     printf("%d ", arr2[y]);
    // }

    return 0;
}
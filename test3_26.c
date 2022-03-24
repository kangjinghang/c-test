#include <stdio.h>
#define N_VALUE 5

int my_strlen(char *str)
{
    char *start = str;
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    return end - start;
}

int main()
{
    // int *p; // 局部变量不初始化，里面默认放的是一个随机值
    // *p = 20;
    // 1.指针运算
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", *p);
        p++;
    }

    p--; // 回到最后一个位置
    // 从数组的最后一个位置指针，每隔2个，倒着输出回来
    for (int i = 0; i < sz; i += 2)
    {
        printf("%d ", *p);
        p -= 2;
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 指针 - 指针 = 中间的元素个数
    printf("%ld\n", &arr[9] - &arr[0]);
    printf("%ld\n", &arr[0] - &arr[9]);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char c_array[] = "bit";
    int len = my_strlen(c_array);
    printf("%d\n", len);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    float values[N_VALUE];
    // C语言标准规定，允许向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，
    // 但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
    // 初始化方式一
    for (float *vp = &values[N_VALUE]; vp > &values[0];)
    {
        *--vp = 0;
    }

    // 初始化方式二
    for (float *vp = &values[N_VALUE - 1]; vp >= &values[0]; vp--)
    {
        *vp = 0;
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 数组与指针
    printf("%p\n", arr);     // 地址 - 首元素的地址 0x7ff7bf713080
    printf("%p\n", &arr[0]); // 0x7ff7bf713080
    printf("%p\n", &arr);    // 取出的是整个数组的地址，从首元素的地址到最后一个元素的地址 0x7ff7bf713080

    printf("%p\n", arr + 1);     // 地址 - 首元素的地址 0x7ff7bf713084 跳过一个int类型长度
    printf("%p\n", &arr[0] + 1); // 0x7ff7bf713084 跳过一个int类型长度
    printf("%p\n", &arr + 1);    // 取出的是整个数组的地址，从首元素的地址到最后一个元素的地址 0x7ff7bf7130a8 跳过整个数组的长度

    // 绝大多数情况下，数组名就是首元素地址
    // 但是有两种情况例外，第一个是 &arr 即 &数组名 的时候，这个时候数组名不是首元素的地址，
    // 数组名表示的是整个数组，&数组名 取出的是整个数组的地址

    // 第二个是 sizeof(arr) - sizeof(数组名)，这是数组名表示的是整个数组，
    // sizeof(数组名)计算的是整个数组的字节大小

    printf("\n");
    p = arr;
    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int a = 11;
    int b = 22;
    int c = 33;
    // 指针数组
    int *arr2[] = {&a, &b, &c};
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *arr2[i]);
    }

    return 0;
}
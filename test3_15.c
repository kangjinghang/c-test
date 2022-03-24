#include <stdio.h>
#include <string.h>

void print(int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}

int my_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        // 指针右移
        str++;
    }
    return count;
}

int my_strlen2(char *str)
{
    if (*str != '\0')
    {
        return 1 + my_strlen2(str + 1);
    }
    else
    {
        return 0;
    }
}

int fib(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;

    while (n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

void bubble_sort(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 1; // 标记本趟排序是有序的
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0; // 说明本趟排序并不是完全有序的
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

int main()
{
    // 递归
    // 输入1245，屏幕打印 1  2  3  4
    unsigned int num = 0;
    // scanf("%d", &num);
    // print(num);

    char arr[] = "bit";
    // arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
    // 模拟实现strlen
    int len = my_strlen(arr);
    printf("长度:%d\n", len);

    len = my_strlen2(arr);
    printf("长度:%d\n", len);

    // 计算斐波那契数列
    // 1 1 2 3 5 8
    int sum = fib(6);
    printf("sum:%d\n", sum);

    // 剩下的元素， 默认初始化为0
    int arr_in[10] = {1, 2, 3};
    // a b \0 \0 \0
    char arr_ch[5] = {'a', 98};
    // a b \0 \0 \0
    char arr_ch2[5] = "ab";
    // arr_ch3[7]，7 = 6 + 1
    char arr_ch3[] = "abcedf";
    // sizeof，计算arr_ch3所占空间的大小，7 * 1 = 7
    printf("%ld\n", sizeof(arr_ch3)); // 7
    printf("%ld\n", strlen(arr_ch3)); // 6，找到'\0'就停止，计算字符串长度不包含'\0'

    int arr_3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr_3) / sizeof(arr_3[0]);
    for (int i = 0; i < sz; i++)
    {
        // 每个元素差4个字节
        printf("&arr_3[%d] = %p \n", i, &arr_3[i]);
    }

    int arr_4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sz = sizeof(arr_4) / sizeof(arr_4[0]);
    // arr是数组，实际上传入的是arr_4首个元素的地址，即&arr_4[0]
    bubble_sort(arr_4, sz);
    for (int i = 0; i < sz; i++)
    {
        // 每个元素差4个字节
        printf("&arr_4[%d] = %d \n", i, arr_4[i]);
    }

    printf("%p\n", arr_4); // 0x7ff7bfc6c020
    printf("%p\n", &arr_4[0]); // 0x7ff7bfc6c020
    printf("%p\n", &arr_4); // 0x7ff7bfc6c020

    printf("%p\n", arr_4 + 1); // 0x7ff7bfc6c024
    printf("%p\n", &arr_4[0] + 1); // 0x7ff7bfc6c024
    printf("%p\n", &arr_4 + 1); // 0x7ff7bfc6c048 = 0x7ff7bfc6c020 + 10 * 4 
    return 0;
}
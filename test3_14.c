#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"

void swap(int *pa, int *pb)
{
    int tmp = 0;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int is_prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int is_leap_year(int x)
{
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
    {
        return 1;
    }
    return 0;
}
int binary_search(int arr[], int k, int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return 1;
}

int add(int *p)
{
    (*p)++;
}

int main()
{
    // 例1，strcpy
    char arr1[] = "bit";
    char arr2[20] = "################";
    // strcpy(arr1, arr2);
    // printf("%s\n", arr2);

    // 例2，memset
    char arr[] = "hello world";
    memset(arr, '*', 5);
    printf("%s\n", arr);

    // 例3，交换两个数
    int a = 10;
    int b = 20;
    // 这里传入的是&a &b
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    // 例4，打印100-200之间的素数
    for (int i = 100; i <= 200; i++)
    {
        if (is_prime(i) == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("\n");

    // 例5，打印1000-2000之间的闰年
    for (int year = 1000; year <= 2000; year++)
    {
        if (is_leap_year(year) == 1)
        {
            printf("%d ", year);
        }
    }
    printf("\n");
    printf("\n");

    // 例6，二分查找法
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(array) / sizeof(array[0]);
    int k = 7;
    int ret = binary_search(array, k, sz);
    if (ret == -1)
    {
        printf("找不到指定的数字\n");
    }
    else
    {
        printf("找到了,下标是:%d\n", ret);
    }

    // 例7，自增3次
    for (int i = 0; i < 3; i++)
    {
        add(&k); // 这里要传地址
    }
    printf("k = %d\n", k);

    ret = Add(a, b);
    printf("ret = %d\n", ret);
    return 0;
}
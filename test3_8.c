#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // 例1，计算n的阶乘
    int n = 5;
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
    }
    printf("%d的阶乘是%d\n", n, ret);
    // 例2，计算1!+2!+3!+...+10!
    n = 10;
    ret = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ret = i * ret;
        sum += ret;
    }
    printf("1!+2!+3!+...+10!的结果是%d\n", sum);

    // 例3，二分查找法
    int arr[] = {1, 2, 4, 5, 6, 7, 8, 9};
    // 计算元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);
    int lo = 0;
    int hi = sz - 1;
    int mid = -1;
    int search = 12;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (search < arr[mid])
        {
            hi = mid - 1;
        }
        else if (search > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            printf("找到了%d\n", mid);
            break;
        }
    }
    if (lo > hi)
    {
        printf("没找到\n");
    }
    // 例4，编写代码，演示多个字符从两端移动，向中间汇聚
    char arr1[] = "hello kang jing hang";
    char arr2[] = "####################";
    int left = 0;
    // 这样算的话，要减2，因为末尾'\0'的存在
    // int right = sizeof(arr1) / sizeof(arr1[0]) -2 ;
    int right = strlen(arr1) - 1;
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);
        sleep(1);
        // system("clear");
        left++;
        right--;
    }
    printf("%s\n", arr2);
    return 0;
}
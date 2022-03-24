#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void revserse(char *str)
{
    int len = strlen(str);
    char *left = str;
    char *right = str + len - 1;

    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main()
{
    int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 二维数组，第一行：1,2,3,4,5，第二行：6,7,8,9,10
    // &aa 取出二维数组的地址，+1跳过整个二维数组，指向数组最后一个元素的下一个位置，强转成 int*
    int *ptr1 = (int *)(&aa + 1);
    // aa这里是首元素地址，就是第一行的地址，+1就是第二行地址，*(aa + 1)=aa[1]，就是第二行数组名，
    // 也是第二行首元素的地址，也是 6 的地址
    int *ptr2 = (int *)(*(aa + 1));

    printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1)); // 10,5

    int arr[10] = {1, 5, 6, 7};
    int *parr = arr;
    // *(p+2) == p[2] == *(arr+2) == arr[2]
    arr[2]; // arr[2] = *(arr+2)

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char *a[] = {"work", "at", "alibaba"}; // a是指针数组，分别存放'w','a','a'的地址
    char **pa = a;                         // a是首元素地址，pa就是指向第一个元素'w'指针的指针
    pa++;                                  // pa++，指向第二个元素'a'
    printf("%s\n", *pa);                   // at

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 自己实现一个翻转字符串的函数
    char str[] = "abcd";
    revserse(str);
    printf("%s\n", str);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 计算sed的前n项之和，比如2+22+222=246
    int sed = 2;
    int n = 5;
    int sum = 0;
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur = cur * 10 + sed;
        sum += cur;
    }
    printf("%d\n", sum);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 打印1-10000之间的水仙花数

    for (int i = 1; i < 10000; i++)
    {
        // 1.计算i的位数
        int c = 1;
        int tmp = i;
        while (tmp /= 10)
        {
            c++;
        }

        // 2.计算i的每一位n次方之和
        tmp = i;
        int s = 0;
        while (tmp)
        {
            s += pow(tmp % 10, c);
            tmp /= 10;
        }

        // 3.比较是否符合
        if (i == s)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 打印菱形图案
    int line = 7;
    // 打印上半部分
    for (int i = 0; i < line; i++)
    {
        // 打印空格
        for (int j = 0; j < line - 1 - i; j++)
        {
            printf(" ");
        }

        // 打印*
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // 打印下半部分

    for (int i = 0; i < line - 1; i++)
    {
        // 打印空格
        for (int j = 0; j <= i; j++)
        {
            printf(" ");
        }

        // 打印*
        for (int j = 0; j < 2 * (line - 1 - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 喝汽水问题，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶汽水
    int money = 20;
    int total = money;
    int empty = total;
    while (empty >= 2) // 只要 empty>=2 就能换汽水喝
    {
        total += empty / 2;
        empty = empty / 2 + empty % 2; // 每次换完可能有剩下的，不足换一瓶汽水，加上上次剩下的
    }
    printf("total=%d\n", total);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 调整奇偶数顺序，使奇数全部位于偶数前面
    int myarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 44, 55, 22, 64, 77, 90};
    int sz = sizeof(myarr) / sizeof(myarr[0]);
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        while (left < right && myarr[left] % 2 != 0) // 从左边找，直到找到一个偶数
        {
            left++;
        }
        while (left < right && myarr[right] % 2 != 1) // 从右边找，直到找到一个奇数
        {
            right--;
        }
        if (left < right)
        {
            int t = myarr[left];
            myarr[left] = myarr[right];
            myarr[right] = t;
        }
    }

    for (int i = 0; i < sz; i++)
    {
        printf("%d ", myarr[i]);
    }

    return 0;
}
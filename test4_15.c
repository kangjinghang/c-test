#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 暴力求解法
void left_move(char *arr, int k)
{
    int len = strlen(arr);
    for (int i = 0; i < k; i++)
    {
        // 左旋一个字符
        char tmp = *arr;
        for (int j = 0; j < len - 1; j++)
        {
            *(arr + j) = *(arr + j + 1);
        }
        *(arr + len - 1) = tmp;
    }
}

// 逆序字符串
void reverse(char *left, char *right)
{
    while (left < right)
    {
        char *tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

// 三步翻转法
// abcdef 切开 量表同时逆序， -> ba fedc 整体再逆序 cdefab
void left_move2(char *arr, int k)
{
    int len = strlen(arr);
    reverse(arr, arr + k - 1);       // 逆序左边
    reverse(arr + k, arr + len - 1); // 逆序右边
    reverse(arr, arr + len - 1);     // 逆序整体
}

int is_left_move(char *s1, char *s2)
{
    int len = strlen(s1);
    for (int i = 0; i < len; i++)
    {
        left_move2(s1, 1); // 避免一次性旋转完后s1被改变，所以是一个字符一个字符旋转，旋转完一个字符就和s2比较一次
        int ret = strcmp(s1, s2);
        if (ret == 0)
            return 1;
    }
    return 0;
}

// abcdef 后面再追加上当前字符串， abcdefabcdef 这样就包含了所以旋转后的可能性，判断是否是其子串即可
int is_left_move2(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
        return 0;
    // 1.在s1字符串中追加一个s1字符串
    strncat(s1, s1, len1); // abcdefabcdef
    // 2.判断s2指向的字符串是否是s1指向的字符串的子串
    char *ret = strstr(s1, s2);
    if (ret == NULL)
        return 0;
    else
        return 1;
}

int find_num(int arr[3][3], int k, int *px, int *py)
{
    int x = 0;
    int y = *py - 1;
    while (x <= *px - 1 && y >= 0)
    {
        if (arr[x][y] > k)
            y--;
        else if (arr[x][y] < k)
        {
            x++;
        }
        else
        {
            // printf("找到了,下标是%d,%d\n", x, y);
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    // 实现一个函数，可以左旋字符串的k个字符
    // 例如：
    // ABCD左旋一个字符得到BCDA
    // ABCD左旋两个字符得到CDAB
    char arr[] = "abcdef";
    // left_move(arr, 2); // 方式一
    left_move2(arr, 2); // 方式二
    printf("%s\n", arr);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 判断arr2是否能由arr1旋转得来
    char arr1[30] = "abcdef";
    char arr2[] = "cdefab";
    int ret = is_left_move(arr1, arr2); // 方式一
    if (ret == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // ret = is_left_move2(arr1, arr2); // 方式二
    if (ret == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    // 杨氏矩阵
    // 有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在
    // 要求：时间复杂度小于O(N)

    int xarr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // 右上角元素和t比较，右上角元素比t大，说明这一行没有要找的元素，右上角的元素比t小，说明这一列没有要找的元素
    // 同理，左下角也是可以的
    int t = 7;
    int x = 3;
    int y = 3;

    ret = find_num(xarr, t, &x, &y);
    if (ret == 1)
    {
        printf("找到了,下标是%d,%d\n", x, y);
    }
    else
    {
        printf("找不到\n");
    }

    return 0;
}
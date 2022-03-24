#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int my_strlen(const char *str)
{
    int count = 0;
    assert(str != NULL);
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int my_strlen2(char *str)
{
    assert(str != NULL);
    if (*str == '\0')
        return 0;
    else
        return 1 + my_strlen2(++str);
}

char *my_strcpy(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
    // 拷贝src指向的字符串到dest指向到空间，包含'\0'
    while (*dest++ = *src++)
    {
    }
    return ret; // 返回目的空间的起始地址
}

char *my_strcat(char *dest, const char *src)
{
    assert(dest && src);
    char *ret = dest;
    // 1.找到目的字符串的'\0'
    while (*dest)
    {
        dest++;
    }
    // 2.追加
    while (*dest++ = *src++)
    {
    }
    return ret;
}

int my_strcmp(const char *str1, const char *str2)
{
    assert(str1 && str2);
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
        {
            // 相等
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *my_strncpy(char *dest, const char *src, int count)
{
    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
    // 拷贝src指向的字符串到dest指向到空间，包含'\0'
    while (count && (*dest++ = *src++))
    {
        count--;
    }
    if (count) // 拷贝完了src所有字符，而且没有用完count
    {
        while (--count)
        {
            *dest++ = '\0'; // 追加几个'\0'进去
        }
    }
    return ret; // 返回目的空间的起始地址
}

int main()
{
    // 1.自己实现strlen
    int len = my_strlen2("abcdef");
    // int len = my_strlen("abcdef");
    printf("%d\n", len);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 2.自己实现strcpy
    char arr1[] = "abcdefghi";
    char arr2[] = "bit";
    printf("%s\n", my_strcpy(arr1, arr2));

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 3.自己实现strcat
    char arr3[] = "hello";
    char arr4[] = "world";
    printf("%s\n", my_strcat(arr3, arr4));

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char *p1 = "abf";
    char *p2 = "abc";
    printf("%d\n", my_strcmp(p1, p2));

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char arr5[10] = "abc";
    char arr6[] = "hello bit";
    printf("%s\n", my_strncpy(arr5, arr6, 4));
    return 0;
}
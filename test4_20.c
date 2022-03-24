#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

char *my_strstr(const char *p1, const char *p2)
{
    assert(p1 && p2);
    char *s1 = NULL;
    char *s2 = NULL;
    char *cur = (char *)p1;
    if (*p2 == '\0')
        return (char *)p1;
    while (*cur)
    {
        s1 = cur;
        s2 = (char *)p2;
        // *p1 == '\0'，说明p1已经到末尾了；*p2 == '\0'，说明p2已经到末尾了，已经查找到了，而且查找完了
        // while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
        while (*s1 && *s2 && (*s1 == *s2))
        {
            s1++;
            s2++;
        }
        // if (*s2 == '\0') // 说明找到了
        if (!*s2) // 说明找到了
        {
            return cur; // 找到了子串
        }
        cur++;
    }
    return NULL; // 找不到子串
}

struct S
{
    char name[20];
    int age;
};

void *my_memcpy(void *dest, const void *src, size_t num)
{
    assert(dest && src);
    void *ret = dest;
    while (num--)
    {
        *(char *)dest++ = *(char *)src++;
    }
    return (void *)ret;
}

void *my_memmove(void *dest, const void *src, size_t num)
{
    assert(dest && src);
    void *ret = dest;
    if (dest < src)
    // if (dest < src || des > src + num)
    {
        // 前 -> 后
        while (num--)
        {
            *(char *)dest++ = *(char *)src++;
        }
    }
    else
    {
        // 后 -> 前
        while (num--)
        {
            *(char *)(dest + num) = *(char *)(src + num);
        }
    }

    return (void *)ret;
}

int main()
{
    // 1.自己实现strstr，查找子字符串
    char *p1 = "abcdefghi";
    char *p2 = "def";
    char *ret = my_strstr(p1, p2);
    if (ret == NULL)
        printf("子串不存在\n");
    else
        printf("%s\n", ret);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char aa[] = "zpw@bitedu.tech";
    char *paa = "@.";

    char *rett = strtok(aa, paa);
    printf("%s\n", rett);
    rett = strtok(NULL, paa);
    printf("%s\n", rett);
    rett = strtok(NULL, paa);
    printf("%s\n", rett);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 常规写法
    rett = NULL;
    for (rett = strtok(aa, paa); rett != NULL; rett = strtok(NULL, paa))
    {
        printf("%s\n", rett);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 错误码 -  错误信息
    // 1     -  Operation not permitted
    // 2     -  No such file or directory
    // errorno 是一个全局的错误码的变量
    // 当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errorno中
    char *str = strerror(1);
    printf("%s\n", str);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        printf("open file success\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char ch = 'w';
    int retch = islower(ch);
    printf("%d\n", retch);
    retch = islower(2);
    printf("%d\n", retch);
    retch = islower(ch);
    printf("%d\n", retch);
    retch = toupper(ch);
    printf("%c\n", retch);
    // 大写转小写
    char xarr[] = "I Am A Student";
    int i = 0;
    while (xarr[i])
    {
        if (isupper(xarr[i]))
        {
            xarr[i] = tolower(xarr[i]);
        }
        i++;
    }
    printf("%s\n", xarr);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    memcpy(arr2, arr1, sizeof(arr1));

    struct S arr3[] = {{"张三", 20}, {"李四", 30}};
    struct S arr4[3] = {0};
    // memcpy(arr4, arr3, sizeof(arr3));
    my_memcpy(arr4, arr3, sizeof(arr3));

    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // my_memcpy(arr5 + 2, arr5, sizeof(arr5)); // 错误的，源地址和目标地址有重叠，不能用这个函数
    my_memmove(arr5 + 2, arr5, sizeof(arr5));
    int sz = sizeof(arr5) / sizeof(arr5[0]);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr5[i]);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    my_memmove(arr5, arr5 + 3, sizeof(arr5));
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr5[i]);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int arr7[] = {1, 2, 3, 4, 5};
    int arr8[] = {1, 2, 5, 4, 3};
    int retarr = memcmp(arr7, arr8, 9);
    printf("%d\n", retarr);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int arr9[10] = {0};
    memset(arr9, 1, 40); // 修改的单位是字节，1 当成字节去修改
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr9[i]);
    }
    return 0;
}
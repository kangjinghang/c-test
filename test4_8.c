#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        // 一趟冒泡排序，一趟排序要进行多少对比较呢？ sz - 1 -i，9 8 7 ...
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int cmp_int(const void *e1, const void *e2)
{
    // 比较两个整形值的
    return *(int *)e1 - *(int *)e2;
}

int cmp_float(const void *e1, const void *e2)
{
    if (*(float *)e1 < *(float *)e2)
    {
        return -1;
    }
    if (*(float *)e1 == *(float *)e2)
    {
        return 0;
    }
    return 1;
}

struct Stu
{
    char name[20];
    int age;
};

int cmp_stu_by_age(const void *e1, const void *e2)
{
    return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
}

int cmp_stu_by_name(const void *e1, const void *e2)
{
    return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
}

void swap_char(char *e1, char *e2, int width)
{
    for (int i = 0; i < width; i++)
    {
        char tmp = *e1;
        *e1 = *e2;
        *e2 = tmp;
        e1++;
        e2++;
    }
}

/**
 * @brief 自定义冒泡排序函数
 *
 * @param base 首元素指针
 * @param sz 数组长度
 * @param width 每个元素占用的字节数
 * @param cmp 自定义排序函数
 */
void q_bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
    for (int i = 0; i < sz - 1; i++)
    {
        // 一趟冒泡排序，一趟排序要进行多少对比较呢？ sz - 1 -i，9 8 7 ...
        for (int j = 0; j < sz - 1 - i; j++)
        {
            char *buf1 = (char *)base + width * j;
            char *buf2 = (char *)base + width * (j + 1);
            if (cmp(buf1, buf2) > 0)
            {
                swap_char(buf1, buf2, width);
            }
        }
    }
}

int main()
{

    int ia = 10;
    int *pia = &ia;
    char *pic = &ia; // 会有警告

    // 1、void*类型的指针，可以接收任意类型的地址（地址垃圾桶不是）
    // 2、void* 类型的指针不能进行解引用操作，因为他不知道要访问几个字节，地址垃圾桶，垃圾那么多哈哈
    // 3、void*类型的指针，不能进行 +/- 整数的操作
    void *pv = &ia;
    // *pv = 0;  // 不能进行解引用操作

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    // 学会使用库函数 qsort
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    // bubble_sort(arr, sz);
    qsort(arr, sz, sizeof(arr[0]), cmp_int); // 库函数
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    float farr[10] = {9.9, 8.4, 7.5, 6.2, 5.0, 4.6, 3.2, 2.9, 1.1, 4.8};
    int fsz = sizeof(farr) / sizeof(farr[0]);
    qsort(farr, fsz, sizeof(farr[0]), cmp_float); // 库函数
    for (int i = 0; i < fsz; i++)
    {
        printf("%f ", farr[i]);
    }

    printf("\n");
    struct Stu s[3] = {{"zhangsan", 30}, {"lisi", 20}, {"wangwu", 40}};
    int ssz = sizeof(s) / sizeof(s[0]);
    qsort(s, ssz, sizeof(s[0]), cmp_stu_by_age); // 按年龄排序
    for (int i = 0; i < ssz; i++)
    {
        printf("name=%s,age=%d\n", s[i].name, s[i].age);
    }

    printf("\n");
    qsort(s, ssz, sizeof(s[0]), cmp_stu_by_name); // 按名字排序
    for (int i = 0; i < ssz; i++)
    {
        printf("name=%s,age=%d\n", s[i].name, s[i].age);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    // 自己定义一个冒泡排序函数
    q_bubble_sort(s, ssz, sizeof(s[0]), cmp_stu_by_age); // 自定义冒泡排序函数，按年龄排序
    for (int i = 0; i < ssz; i++)
    {
        printf("name=%s,age=%d\n", s[i].name, s[i].age);
    }

    printf("\n");

    q_bubble_sort(s, ssz, sizeof(s[0]), cmp_stu_by_name); // 自定义冒泡排序函数，按名字排序
    for (int i = 0; i < ssz; i++)
    {
        printf("name=%s,age=%d\n", s[i].name, s[i].age);
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 笔试题
    // 数组名是首元素地址
    // 以下两种情况除外：
    //   1.sizeof(数组名) - 数组名表示整个数组
    //   2.&数组名 - 数组名表示整个数组
    int a[] = {1, 2, 3, 4};
    printf("%lu\n", sizeof(a));         // 16，数组占用空间的总大小，单位是字节，4*4=16
    printf("%lu\n", sizeof(a + 0));     // 8，数组名这里表示首元素地址，a+0 还是首元素地址，是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(*a));        // 4，数组名表示首元素地址，*a就是首元素
    printf("%lu\n", sizeof(a + 1));     // 8，数组名这里表示首元素地址，a+0 是第二个元素地址，是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(a[1]));      // 4，第二个元素的大小
    printf("%lu\n", sizeof(&a));        // 8，&a取出的是数组的地址，数组的地址也是是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(*&a));       // 16，&a取出的是数组的地址，数组的地址解引用访问的是数组的地址，那么就是计算数组的大小，同sizeof(a)
    printf("%lu\n", sizeof(&a + 1));    // 8，&a取出的是数组的地址，&a+1虽然地址跳过了整个数组，但还是地址，所以是4/8字节
    printf("%lu\n", sizeof(&a[0]));     // 8，&a[0]是第一个元素的地址
    printf("%lu\n", sizeof(&a[0] + 1)); // 8，&a[0]+1是第二个元素的地址

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 字符数组
    char b[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%lu\n", sizeof(b));         // 6，数组占用空间的总大小，单位是字节，6*1=6
    printf("%lu\n", sizeof(b + 0));     // 8，数组名这里表示首元素地址，b+0 还是首元素地址，是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(*b));        // 1，数组名表示首元素地址，*a就是首元素，首元素是字符，大小就是1个字节
    printf("%lu\n", sizeof(b[1]));      // 1，第二个元素的大小
    printf("%lu\n", sizeof(&b));        // 8，&b取出的是数组的地址，数组的地址也是是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(&b + 1));    // 8，&b取出的是数组的地址，&b+1虽然地址跳过了整个数组，但还是地址，所以是4/8字节
    printf("%lu\n", sizeof(&b[0] + 1)); // 8，&b[0]+1是第二个元素的地址

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    printf("%lu\n", strlen(b));     // 随机值
    printf("%lu\n", strlen(b + 0)); // 随机值
    // printf("%lu\n", strlen(*b));        // error，非法访问内存，strlen需要传入的是地址，但是传入是*b，就是将首元素地址解引用，就是首元素'a'，将'a'的ascii值当成地址传入strlen函数
    // printf("%lu\n", strlen(b[1]));      // error，非法访问内存，同上
    printf("%lu\n", strlen(&b));        // 随机值，&b取出的是数组的地址，数组的地址也是是地址，和strlen(b)结果相同
    printf("%lu\n", strlen(&b + 1));    // 随机值-6，&b取出的是数组的地址，&b+1地址跳过了整个数组，所以比上面的随机值少数组b的长度6
    printf("%lu\n", strlen(&b[0] + 1)); // 随机值-1，&b[0]+1是第二个元素的地址，所以比上面的随机值少数组b的长度6
    return 0;
}
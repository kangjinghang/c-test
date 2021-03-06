#include <stdio.h>

// 结构体关键字 结构体标签
// struct Stu
// struct Stu // 结构体类型
typedef struct Stu
{
    // 成员变量
    char name[20];
    short age;
    char tel[12];
    char sex[5];
    // } Stu s1, s2, s3; // 全局变量
} Stu;

struct S

{
    int a;
    char c;
    char arr[20];
    double d;
};

struct T
{
    char ch[10];
    struct S s;
    char *pc;
};

void Print(Stu *ps) // 局部变量是指针，拷贝仅占用8个字节
{
    printf("%s\n", ps->name);
    printf("%d\n", ps->age);
    printf("%s\n", ps->tel);
    printf("%s\n", ps->sex);
}

int count_bit_one(unsigned int a)
{
    int count = 0;
    while (a)
    {
        if (a % 2 == 1)
        {
            count++;
        }
        a /= 2;
    }
    return count;
}

int count_bit_one2(int a)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((a >> i) & 1 == 1)
        {
            count++;
        }
    }
    return count;
}

int count_bit_one3(int a)
{
    int count = 0;
    while (a)
    {
        a = a & (a - 1);
        count++;
    }

    return count;
}

int main()
{
    // struct Stu s = {"xiaowang", 18, "12031133563", "女性"};
    Stu s = {"xiaowang", 18, "12031133563", "女性"};
    char arr[] = "hello bit\n";
    struct T t = {"hello", {"100", 'w', "world", 3.14}, arr};
    printf("%s\n", t.ch);
    printf("%s\n", t.s.arr);
    printf("%lf\n", t.s.d);
    printf("%d\n", t.s.a);
    printf("%p\n", t.pc);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    Print(&s);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 写一个函数，求a的二进制（补码）中1的个数
    int a = 13;
    // 1101
    int ret = count_bit_one(a);
    printf("%d\n", ret);
    a = -1;
    ret = count_bit_one(a);
    printf("%d\n", ret);

    a = 13;
    ret = count_bit_one2(a);
    printf("%d\n", ret);

    a = -1;
    ret = count_bit_one2(a);
    printf("%d\n", ret);

    a = 13;
    ret = count_bit_one3(a);
    printf("%d\n", ret);

    a = -1;
    ret = count_bit_one3(a); // 最简洁
    printf("%d\n", ret);
    return 0;
}
#include <stdio.h>
#include <string.h>
#define MAX 10

// num2是全局变量
int num2 = 20;

// 枚举定义
enum Sex
{
    MALE,
    SEMALE,
    SECRET
};

// main前面的int表示main函数调用返回一个整型值
int main()
{
    // printf("hello world\n");
    char ch = 'A';
    printf("%c\n", ch);
    int age = 20;

    printf("%d\n", age);
    short s_age = 11;
    printf("%d\n", s_age);
    float f = 5.0;
    printf("%f\n", f);
    double d = 3.14;
    printf("%lf\n", d);
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long long));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));

    // 未声明的标识符
    // extern int g_val;
    // printf("g_val = %d\n", g_val);

    // num1是局部变量
    int num1 = 10;

    int a = 0;
    int b = 0;

    // scanf("%d,%d", &a, &b);
    int sum = a + b;
    printf("sum = %d\n", sum);
    printf("--------------------\n");

    int n = 10;
    int arr[10] = {0};
    int array[MAX] = {1};
    printf("%d\n", MAX);
    enum Sex s = SECRET;
    printf("%d\n", MALE);
    printf("%d\n", SEMALE);
    printf("%d\n", SECRET);

    printf("--------------------\n");
    // 字符串
    char arr1[] = "abc";
    printf("%s\n", arr1);
    char arr2[] = {'a', 'b', 'c', '\0'};
    printf("%s\n", arr2);
    printf("%d\n", strlen(arr1));
    printf("%d\n", strlen(arr2));
    return 0;
}
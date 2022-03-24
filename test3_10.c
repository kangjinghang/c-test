#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("************************************\n");
    printf("******    1.play   0.exit      *****\n");
    printf("************************************\n");
}

void game()
{
    // printf("猜数字\n");
    // 1-100的数字
    int ret = rand() % 100 + 1;
    // printf("%d\n", ret);
    // 2.猜数字
    int guess = 0;
    while (1)
    {
        printf("请猜数字:>\n");
        scanf("%d", &guess);
        if (guess > ret)
        {
            printf("猜大了\n");
        }
        else if (guess < ret)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("恭喜你,猜对了!\n");
            break;
        }
    }
}

int main()
{
    // 例1，输入3个数，然后从大到小按顺序输出
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d,%d,%d", &a, &b, &c);
    // a放最大，b放中间，c放最小
    if (a < b)
    {
        int tmp = 0;
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a < c)
    {
        int tmp = 0;
        tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = 0;
        tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d %d %d\n", a, b, c);

    // 例2，给定两个数，求这两个数的最大公约数
    int m = 24;
    int n = 18;
    int r = 1;
    // 欧几里得算法
    while ((r = m % n) != 0)
    {
        // r = m % n;
        m = n;
        n = r;
    }
    printf("最大公约数是:%d\n", n);

    // 例3，打印100到200之间的素数
    int count = 0;
    for (int i = 101; i <= 200; i += 2)
    // 效率低写法：for (int i = 100; i <= 200; i++)
    {
        // 试错法
        int j = 2;
        // 开方
        for (j = 2; j <= sqrt(i); j++)
        // 效率低写法：for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i))
        // 效率低写法：if (i == j)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    printf("%d个素数\n", count);

    // 例4，统计一下1到100之间整数中有多少个数字9
    count = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (i % 10 == 9)
        {
            count++;
        }
        if (i / 10 == 9)
        {
            count++;
        }
    }
    printf("1到100之间整数中有%d个数字9\n", count);

    // 例5，分数求和，计算1/1-1/2+1/3-1/4+1/5+...+1/99-1/100的值，打印结果
    double sum = 0;
    int flag = 1;
    for (int i = 1; i <= 100; i++)
    {
        sum = sum + 1.0 / i * flag;
        flag = -flag;
    }
    printf("1/1-1/2+1/3-1/4+1/5+...+1/99-1/100的和为%lf\n", sum);

    // 例6，在屏幕上输出9*9乘法口诀
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%-2d ", i, j, i * j);
        }
        printf("\n");
    }

    // 例7，猜数字游戏
    // 1.生成一个随机数
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("请选择>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);

    return 0;
}
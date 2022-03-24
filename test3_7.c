#include <stdio.h>

/**
 * while 循环和 for 循环的用法
 *
 */
int main()
{
    // 例1
    // int ch = 0;
    // // EOF，文件结束标志，直到输入 ctrl+z ，即遇到EOF后自动跳出循环
    // while ((ch = getchar()) != EOF)
    // {
    //     putchar(ch);
    // }

    // 例2
    int ret = 0;
    char password[20] = {0};
    printf("请输入密码:>");
    scanf("%s", password); // 输入密码，并存放在password数组中
    printf("请确认(Y/N):>");
    int ch = 0;
    // 避免比如密码输入的是'abc 1234'的情况，一直读取到出现'\n'，代表已经读到了最末尾
    while ((ch = getchar()) != '\n')
    {
        ;
    }

    // getchar(); // 这一步是清除缓冲区的'\n'，非常重要
    ret = getchar();
    // 输入‘123456\n’后，‘123456’被scanf()取走，输入缓冲区剩下了'\n'，然后被getchar()读取，所以 ret='\n'了
    if (ret == 'Y')
    {
        printf("确认成功\n");
    }
    else
    {
        printf("放弃确认\n");
    }

    // 例3
    // while ((ch = getchar()) != EOF)
    // {
    //     if (ch < '0' || ch > '9')
    //         continue;
    //     putchar(ch);
    // }

    // 下面是for循环
    int i = 0;
    // 初始化;判断;改变循环条件
    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    // 例4
    int x = 0;
    int y = 0;
    for (; x < 10; x++)
    {
        // 只打印10次，因为第一次外层循环x=0时，y已经循环到10，第二次外层循环x=1时，y=10不变，判断失败，不会打印
        for (; y < 10; y++)
        {
            printf("hehe\n");
        }
    }

    // 例5，打印1000到2000年之间的闰年
    int year = 0;
    int count = 0;
    for (year = 1000; year <= 2000; year++)
    {
        if (year % 4 == 0 && year % 100 != 0)
        {
            printf("%d是闰年\n", year);
            count++;
        }
        else if (year % 400 == 0)
        {
            printf("%d是闰年\n", year);
            count++;
        }
        year++;
    }
    printf("1000到2000年之间的闰年有%d个\n", count);
    return 0;
}
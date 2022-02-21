#include <stdio.h>

int add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int a = 0;
    int b = ~a;
    printf("%d\n", b);

    int sum = add(2, 4);
    printf("%d\n", sum);
    printf("----------------------\n");
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    while (i < 10)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return 0;
}

// while 循环语句
// int main()
// {
//     int line = 0;
//     printf("加入比特\n");
//     while (line < 2000)
//     {
//         printf("敲一行代码：%d\n", line);
//         line++;
//     }
//     printf("好offer\n");
//     return 0;
// }

// if 语句
// int main()
// {
//     printf("加入比特\n");
//     printf("你要好好学习吗？（1/0）\n");
//     int input = 0;
//     scanf("%d",&input);
//     if(input == 1)
//         printf("好offer\n");
//     else
//         printf("卖红薯\n");
//     return 0;
// }

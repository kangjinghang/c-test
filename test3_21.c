#include <stdio.h>

int main()
{
    // 例1，计算给定数字在内存中的1的个数
    int a = -1;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((a >> i) & 1) == 1)
        {
            count++;
        }
    }
    printf("%d在内存中1的个数是:%d\n", a, count);
    return 0;
}
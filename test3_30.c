#include <stdio.h>
#include <string.h>

int check_sys()
{
    // 低地址 -------------------> 高地址
    //       01 00 00 00
    // 查看第一个字节的内容
    // 小端：01 00 00 00
    // 大端：00 00 00 01
    // int a = 1;
    // char *p = (char *)&a;
    // return *p;
    int a = 1;
    return *(char *)&a;
}

int main()
{
    1 + (-1);
    // 00000000000000000000000000000001
    // 11111111111111111111111111111111
    // 100000000000000000000000000000000 33位
    // 截断后32位，存储为0

    int x = 20;
    // 00000000000000000000000000010010
    // 0x00000014
    //     14000000       小端:低位的数据保存在低位地址中，高位的数据保存在高位地址中
    // 低地址 -------------------> 高地址
    //     00000014       大端:低位的数据保存在高位地址中，高位的数据保存在低位地址中
    int ret = check_sys();
    if (ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char a = -1;
    signed char b = -1;
    unsigned char c = -1;
    // a = 11111111 -> 整形提升 11111111111111111111111111111111
    // b = 11111111 -> 整形提升 11111111111111111111111111111111
    // c = 11111111 -> 整形提升 00000000000000000000000011111111
    // printf("a=%c,b=%c,c=%c\n", a, b, c);

    printf("a=%d,b=%d,c=%d\n", a, b, c);

    char d = -128;
    // 原码：100000000 00000000 00000000 10000000
    // 反码：111111111 11111111 11111111 01111111
    // 补码：111111111 11111111 11111111 10000000
    // d只能存下最后一个字节，10000000
    // %u - 打印十进制的无符号数字
    // 整型提升，10000000 -> 111111111 11111111 11111111 10000000 还是补码
    // 正常来说如果是 %d ，那么需要 将补码 111111111 11111111 11111111 10000000 转成 原码，然后打印
    // 但是这里是 %u 按无符号打印，那么就是说原、反、补相同
    // 111111111 11111111 11111111 10000000 就是原码
    printf("%u\n", d);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int i = -20;
    unsigned int j = 10;

    // -20
    // 原码 - 10000000 00000000 00000000 00010100
    // 反码 - 11111111 11111111 11111111 11101011
    // 补码 - 11111111 11111111 11111111 11101100
    // 10
    // 补码 - 00000000 00000000 00000000 00001010
    // 相加 - 11111111 11111111 11111111 11110110 (结果的补码)
    // 反码 - 11111111 11111111 11111111 11110101 (结果的反码)
    // 原码 - 10000000 00000000 00000000 00001010 (结果的原码) = -10
    printf("%d\n", i + j);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char ch[1000];
    for (int y = 0; y < 1000; y++)
    {
        ch[y] = -1 - y;
    }
    // -1 -2 -> -128 127 126 -> 3 2 1 0
    // strlen统计到\0 128 + 127 = 255
    printf("%d\n", strlen(ch));

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    double dd = 1E10;
    printf("%lf\n", dd);
    int n = 9;
    float *pFloat = (float *)&n;
    printf("n的值为: %d\n", n); // 9
    printf("*pFloat的值为: %f\n", *pFloat); // 0.000000
    *pFloat = 9.0;
    printf("n的值为: %d\n", n); // 1091567616
    printf("*pFloat的值为: %f\n", *pFloat); // 9.000000
    // IEEE 754标准 任何一个二进制浮点数可以表示成 (-1)^S  * M * 2^E
    // (-1)^S 表示符号位，当s=0，V为正数，当s为1，V为负数
    // M表示有效数字，大于等于1，小于2
    // 2^E表示指数位
    // 比如 9.0 -> 二进制形式 1001.0
    //  (-1)^0 * 1.001 * 2^3
    // S = -1 M = 1.001 E = 3
    // IEEE 754标准 
    // 对于32位浮点数，最高的1位是符号位S，接着的8位是指数E，剩下的23位为有效数字M
    // S(1bit) E(8bit) M(23bit)
    // 对于64位浮点数，最高的1位是符号位S，接着的11位是指数E，剩下的52位为有效数字M
    // S(1bit) E(11bit) M(52bit)
    //  1<= M < 2，所以M只存小数位，不用再存1了
    // 再比如 0.5 = (-1)^1 * 1.0 * 2^-1
    // 关于E，出现负数的情况，需要加上一个中间值，32位加上中间值127，-1+127=126，实际存的E是126
    // 来自己试一下怎么算
    // 5.5 -> 二进制 101.1
    // (-1)^0 * 1.011 * 2^2
    // S = 0 M = 1.011 E = 2(2+127=129)
    // 0 10000001  0110000000000000000000 -> 0x40b00000
    return 0;
}
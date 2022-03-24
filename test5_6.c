#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

int main()
{
    int a = 10000;
    FILE *pf = fopen("test1.txt", "wb");
    fwrite(&a, 4, 1, pf);
    fclose(pf);
    pf = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    FILE *pc = fopen("test3_5.c", "r");
    if (pc == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }

    // 打开成功
    // 读取文件

    // 关闭文件
    fclose(pc);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    FILE *pwc = fopen("test3.txt", "w");
    if (pwc == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }

    // 写入文件
    fputc('b', pwc);
    fputc('i', pwc);
    fputc('t', pwc);

    // 关闭文件
    fclose(pwc);

    FILE *prc = fopen("test3.txt", "r");
    if (prc == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }

    // 读取文件
    printf("%c", fgetc(prc)); // b
    printf("%c", fgetc(prc)); // i
    printf("%c", fgetc(prc)); // t
    printf("\n");

    // 关闭文件
    fclose(prc);

    int ch = fgetc(stdin); // 键盘 - 标准输入设备
    fputc(ch, stdout);     // 屏幕 - 标准输出设备
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

struct S
{
    int n;
    float score;
    char arr[10];
};

int main()
{
    // 原始文件：
    // bit
    // hello
    FILE *prc = fopen("test3.txt", "r");
    if (prc == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }

    // 读取文件
    char buf[1024] = {0};
    fgets(buf, 1024, prc);
    printf("%s", buf); // buf = [b][i][t][\n]
    fputs(buf, stdout);

    fgets(buf, 1024, prc);
    printf("%s\n", buf); // buf = [h][e][l][l][o]
    fputs(buf, stdout);

    // 关闭文件
    fclose(prc);
    prc = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    FILE *pwc = fopen("test3.txt", "w");
    if (pwc == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }
    fputs("bit\n", pwc);
    fputs("hello", pwc);

    // 关闭文件
    fclose(pwc);
    pwc = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");
    fgets(buf, 1024, stdin);
    fputs(buf, stdout);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    struct S s = {100, 3.14f, "bit"};
    FILE *pwc2 = fopen("test4.txt", "w");
    if (pwc2 == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }
    // 格式化的形式写入文件
    fprintf(pwc2, "%d %f %s", s.n, s.score, s.arr);

    // 关闭文件
    fclose(pwc2);
    pwc2 = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    FILE *prc2 = fopen("test4.txt", "r");
    if (prc2 == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }
    struct S ws = {0};

    // 格式化的形式读取文件
    fscanf(prc2, "%d %f %s", &(ws.n), &(ws.score), ws.arr);
    printf("%d %f %s", ws.n, ws.score, ws.arr);

    // 关闭文件
    fclose(prc2);
    prc2 = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 把格式化的数据转换成字符串存储到buf
    sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
    printf("%s\n", buf);

    struct S ws2 = {0};
    // 从buf中读取格式化的字符串到ws2
    sscanf(buf, "%d %f %s", &(ws2.n), &(ws2.score), ws2.arr);
    printf("%d %f %s\n", ws2.n, ws2.score, ws2.arr);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 随机读取示例
    FILE *pwc6 = fopen("test6.txt", "r");
    if (pwc6 == NULL)
    {
        printf("%s\n", strerror(errno)); // No such file or directory
        return 0;
    }

    printf("%ld\n", ftell(pwc6)); // 0 刚开始的时候是偏移量是0
    // 1.定位文件指针
    fseek(pwc6, 2, SEEK_CUR);
    printf("%ld\n", ftell(pwc6)); // 2 现在的偏移量是2

    // 2.读取文件
    int ch6 = fgetc(pwc6); // c
    printf("%c\n", ch6);
    printf("%ld\n", ftell(pwc6)); // 3 因为刚才读取过了一个字符，所以偏移量+1=3

    printf("\n");

    fseek(pwc6, -2, SEEK_END);
    ch6 = fgetc(pwc6); // e
    printf("%c\n", ch6);
    long pos = ftell(pwc6); // 相对于起始位置的偏移量
    printf("%ld\n", pos);

    // 让文件指针的位置回到起始位置
    rewind(pwc6);
    ch6 = fgetc(pwc6); // a
    printf("%c\n", ch6);

    // 关闭文件
    fclose(pwc6);
    pwc6 = NULL;

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // feof函数的使用
    // 不能用feof函数的返回值直接来判断是否文件结束了
    // 而是应当用于当文件读取结束的时候，判断是否读取失败结束，还是遇到文件尾结束
    // 1.文本文件读取是否结束，判断返回值是否为EOF（fgetc），或者是NULL（gets）
    // 例如：fgetc判断是否为EOF，fgets判断返回值是否为NULL
    // 2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
    // 例如：fread判断返回值是否小于实际要读的个数
    FILE *pwc7 = fopen("test7.txt", "r");
    if (pwc7 == NULL)
    {
        perror("open file test7.txt");
        return 0;
    }
    int c;
    while ((c = fgetc(pwc7)) != EOF)
    {
        fputc(c, stdout);
    }
    printf("\n");

    if (ferror(pwc7))
    {
        fputs("I/O error when reading\n", stdout);
    }
    else if (feof(pwc7))
    {
        fputs("End of file reached successfully\n", stdout);
    }

    // 关闭文件
    fclose(pwc7);
    pwc7 = NULL;

    return 0;
}
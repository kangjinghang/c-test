#include <stdio.h>

int main()
{
    int a = 10; // 假设a的地址是0x7ff7bb0a00b8，值是10
    // &a  取地址
    // 指针变量就是存放地址的
    int *p = &a; // a的地址(0x7ff7bb0a00b8)存放到p变量里
    printf("%p\n", &a);
    printf("%p\n", p);
    // *p， *就是解引用操作符，*p就是找到a的值
    *p = 20; // *p就是通过p找到a，0x7ff7bb0a00b8这块内存的值改成20
    printf("%d\n", a);

    char ch = 'w';
    char *pc = &ch;
    *pc = 'x';
    printf("%c\n", ch);
    printf("%d\n", sizeof(pc));
    return 0;
}
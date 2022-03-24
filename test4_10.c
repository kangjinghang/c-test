#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Test
{
    int num;
    char *pcName;
    short sData;
    char cha[2];
    short sBa[4];
} * Tp;

int main()
{
    // 字符串
    char b[] = "abcdef";                // a b c d e f \0 7个元素
    printf("%lu\n", sizeof(b));         // 7，数组占用空间的总大小，单位是字节，加上'\0'，7*1=7
    printf("%lu\n", sizeof(b + 0));     // 8，数组名这里表示首元素地址，b+0 还是首元素地址，是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(*b));        // 1，数组名表示首元素地址，*a就是首元素，首元素是字符，大小就是1个字节
    printf("%lu\n", sizeof(b[1]));      // 1，第二个元素的大小
    printf("%lu\n", sizeof(&b));        // 8，&b取出的是数组的地址，数组的地址也是是地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(&b + 1));    // 8，&b取出的是数组的地址，&b+1虽然地址跳过了整个数组，但还是地址，所以是4/8字节
    printf("%lu\n", sizeof(&b[0] + 1)); // 8，&b[0]+1是第二个元素的地址

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    printf("%lu\n", strlen(b));     // 6
    printf("%lu\n", strlen(b + 0)); // 6
    // printf("%lu\n", strlen(*b));        // error，非法访问内存，strlen需要传入的是地址，但是传入是*b，就是将首元素地址解引用，就是首元素'a'，将'a'的ascii值当成地址传入strlen函数
    // printf("%lu\n", strlen(b[1]));      // error，非法访问内存，同上
    printf("%lu\n", strlen(&b));        // 6，&b取出的是数组的地址，数组的地址也是是地址，和strlen(b)结果相同，char(*p)[7] = &arr
    printf("%lu\n", strlen(&b + 1));    // 随机值，&b取出的是数组的地址，&b+1地址跳过了整个数组，但还是个地址
    printf("%lu\n", strlen(&b[0] + 1)); // 5，&b[0]+1是第二个元素的地址，所以是6-1=5

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 字符串
    char *p = "abcdef";                 // 将常量字符串中 'a' 的地址存放到 p 了
    printf("%lu\n", sizeof(p));         // 8，计算指针变量 p 的大小
    printf("%lu\n", sizeof(p + 1));     // 8，p + 1 还是地址，也就是字符 'b' 的地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(*p));        // 1，*p就是首元素，首元素是字符 'a'，大小就是1个字节
    printf("%lu\n", sizeof(p[0]));      // 1，例：int arr[10]; arr[0] = *(arr+0); 同样的 p[0] = *(p+0)，那么 p[0] == *(p+0) == 'a'，就还是字符 'a' 的地址
    printf("%lu\n", sizeof(&p));        // 8，&p 取出的是指针 p 的地址，那么大小就是4/8字节
    printf("%lu\n", sizeof(&p + 1));    // 8，&p 取出的是指针 p 的地址，&p+1 虽然地址跳过了 p，但还是地址，所以是4/8字节
    printf("%lu\n", sizeof(&p[0] + 1)); // 8，&p[0]+1 是第二个元素 'b' 的地址

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char *q = "abcdef";             // 将常量字符串中 'a' 的地址存放到 q 了
    printf("%lu\n", strlen(q));     // 6，q 存放的是 'a' 的地址，继续向后查找，直到'\0'
    printf("%lu\n", strlen(q + 1)); // 5，q + 1 还是地址，也就是字符 'b' 的地址
    // printf("%lu\n", strlen(*q));        // error，非法访问内存，strlen 需要传入的是地址，但是传入是 *q，就是将首元素地址解引用，就是首元素 'a'，将 'a' 的ascii值当成地址传入 strlen 函数
    // printf("%lu\n", strlen(q[0]));      // error，非法访问内存，同上
    printf("%lu\n", strlen(&q));        // 随机值，&q 取出的是指针 q 的地址，后面的内存分布情况位置，所以是随机值
    printf("%lu\n", strlen(&q + 1));    // 随机值，&q 取出的是指针 q 的地址，&q+1 虽然地址跳过了 p，但还是地址，所以是随机值
    printf("%lu\n", strlen(&q[0] + 1)); // 5，&p[0]+1 是第二个元素 'b' 的地址，所以长度=6-1=5

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 二维数组
    int a[3][4] = {0};                     // 3行4列的二维数组
    printf("%lu\n", sizeof(a));            // 48，数组占用空间的总大小，单位是字节，3*4*4=48
    printf("%lu\n", sizeof(a[0][0]));      // 4，一个整型元素的大小
    printf("%lu\n", sizeof(a[0]));         // 16，每一行数组的名字其实就是 a[0]、a[1]、a[2]，就是说a[0]理解成第一行数组名，sizeof(数组名)就是计算这一行所占用内存的大小=4*4=16
    printf("%lu\n", sizeof(a[0] + 1));     // 8，a[0] 是第一行的数组名，在这里表示首元素的地址(不是那两种特殊情况，sizeof(数组名) 和 &数组名)，就是第一行第一个元素a[0][0]的地址，+1就是第一行第二个元素的地址，是地址就是4/8个字节
    printf("%lu\n", sizeof(*(a[0] + 1)));  // 4，a[0] + 1是第一行第二个元素的地址，整形大小4个字节
    printf("%lu\n", sizeof(a + 1));        // 8，a 是二维数组的数组名，没有sizeof或取地址，所以这里表示首元素地址，二维数组的首元素地址是第一行的地址，+1就是第二行的地址，是地址就是4/8个字节
    printf("%lu\n", sizeof(*(a + 1)));     // 16，a+1就是第二行的地址，等价于 sizeof(a[1])，第二行数组的大小，4*4=16
    printf("%lu\n", sizeof(&a[0] + 1));    // 8，&a[0]+1是第二行的地址，&a[0] 是第一行地址，+1就是第二行地址
    printf("%lu\n", sizeof(*(&a[0] + 1))); // 16，&a[0]+1是第二行的地址，解引用，就是计算第二行数组的大小，4*4=16
    printf("%lu\n", sizeof(*a));           // 16，a是首元素的地址，就是第一行的地址，解引用，就是计算第一行数组的大小，4*4=16
    printf("%lu\n", sizeof(a[3]));         // 16，a[3]虽然不存在，但是实际不会计算，所以不会报错，仍然是当成第四行数组的大小来计算

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int x[5] = {1, 2, 3, 4, 5};  //
    int *pxtr = (int *)(&x + 1); // &x 是数组地址，+1是跳过整个数组，指向数组末尾之后的下一个地址
    // *(x + 1)，x 这里表示首元素 1 的地址，+1，就是第二个元素的地址，解引用，就是2
    printf("%d,%d\n", *(x + 1), *(pxtr - 1)); // 2,5。pxtr-1是向前挪动一个整型的大小，指向5了，解引用，所以 *(pxtr - 1)=5

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // 假设Tp的值是0x100000，如下表达式的值分别是多少
    // 已知，结构体Test的变量大小是32个字节
    Tp = (struct Test *)0x100000;
    printf("%p\n", Tp + 0x1);                 // 0x100014，跳过一个Test的大小，就是0x100000+32=0x100020
    printf("%p\n", (unsigned long)Tp + 0x1);  // 0x100001，Tp转成整数，+1，当成整数计算，就是实实在在的+1，就是0x100001
    printf("%p\n", (unsigned int *)Tp + 0x1); // 0x000004，Tp强制转成无符号整型指针 unsigned int *，+1就是挪动一个整型的大小，4个字节

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int yarr[4] = {1, 2, 3, 4};

    int *ptyarr1 = (int *)(&yarr + 1);
    // 4，&a + 1，数组指针跨过整个数组，强制转成整形指针
    // 00 00 00 01 内存布局: 01 00 00 00，(int)a + 1移动1个字节，就是从01移动到了00，
    // 因为又转成了整形指针，加上后面2的第一个低位字节，所以 就是 00 00 00 02，小端转化 0x020000000
    int *ptyarr2 = (int *)((int)yarr + 1);

    // printf("%x,%x\n", ptyarr1[-1], *ptyarr2); // 0x10，0x200000

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int za[3][2] = {(0, 1), (2, 3), (4, 5)}; // 注意，括号表达式，1,3, 5,0, 0,0
    int *zp;
    zp = za[0];            // a[0] = 1,3 一维数组，p指向二维数组第一行第一个元素1
    printf("%d\n", zp[0]); // p[0]=*(p+0)=1

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int ma[5][5];
    int(*map)[4];
    map = ma; // int(*)[5] 强转位 int(*)[4] 赋值给map，map是指向整形数组的指针，指针有4个元素
    // map[4] = *(p+4)，即p+4，就是跳过4次有4个元素的数组的长度，就是16个整型值，&map[4][2] = *(*(p+4)+2)
    // map[4][2] 指向 0 + 4*4 + 2 = 18
    // ma[4][2] 指向 4*5 + 2 = 22
    // &map[4][2] - &ma[4][2] = 18 - 22 = -4
    // %p 是按指针打印，地址不纯在原、反、补，直接打印将-4的反码按无符号数打印即可 0xfffffffc
    printf("%p,%d\n", &map[4][2] - &ma[4][2], &map[4][2] - &ma[4][2]);
    return 0;
}
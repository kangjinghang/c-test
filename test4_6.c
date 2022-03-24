#include <stdio.h>

void test(int (*px)[5]) // 首元素的地址，就是一个一维数组地址
{
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

void Print(char *str)
{
    printf("%s\n", str);
}

void menu()
{
    printf("**************************\n");
    printf("***  1.add      2.sub  ***\n");
    printf("***  3.mul      4.div  ***\n");
    printf("***        0.exit     ****\n");
    printf("**************************\n");
}

int main()
{
    const char *p2 = "abcdef"; // 首字符'a'的地址赋值给p2
    int arr2[5];
    int(*pa)[5] = &arr2; // 取出数组的地址，pa就是一个数组指针

    int arr[3][5] = {0};
    test(arr);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int a = 10;
    int b = 20;
    printf("%d\n", Add(a, b));
    // &函数名 和 函数名 都是函数的地址
    printf("%p\n", &Add); // 0x103a9de70 函数地址
    printf("%p\n", Add);  // 0x103a9de70 函数地址
    // padd 是 函数指针
    int (*padd)(int, int) = Add;

    printf("%d\n", (*padd)(2, 3));
    printf("%d\n", (**padd)(2, 3));
    printf("%d\n", (***padd)(2, 3));
    // 上面3行的结果完全相同，说明 *、**、*** 放在这里完全就是摆设，没啥实际用途
    printf("%d\n", (padd)(2, 3)); // 甚至，不写 * 也是可以的，padd就是一个地址，而Add函数其实也是一个地址
    printf("%d\n", padd(2, 3));   // 甚至，不写 * 也是可以的，padd就是一个地址，而Add函数其实也是一个地址

    void (*pt)(char *) = Print;
    (*pt)("hello world");

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    // my_func 是一个函数声明
    // my_func 函数的参数有两个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回值是void
    // my_func 函数的返回类型也是一个函数指针，该函数指针指向的函数的参数是int，返回值是void
    void (*my_func(int, void (*)(int)))(int);

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int (*parr[4])(int, int) = {Add, Sub, Mul, Div}; // 函数指针的数组

    int (*(*pparr)[4])(int, int) = &parr; // pparr是一个数组指针，指针指向的数组有4个元素

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", parr[i](6, 2));
    }

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    int input = 0;
    int x = 0;
    int y = 0;
    int (*calArr[5])(int, int) = {0, Add, Sub, Mul, Div}; // 转移表
    do
    {
        menu();
        printf("请选择:>\n");
        scanf("%d", &input);
        if (input >= 1 && input <= 4)
        {
            printf("请输入两个操作数:>\n");
            scanf("%d %d", &x, &y);
            int ret = calArr[input](x, y);
            printf("%d\n", ret);
        }
        else if (input == 0)
        {
            printf("退出\n");
        }
        else
        {
            printf("选择错误\n");
        }

    } while (input);

    return 0;
}
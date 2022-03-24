#include <stdio.h>
#include <assert.h>

// const char *src，*src 是不能被改变的，更加健壮
char *my_strcpy(char *dest, const char *src)
{
    // while (*src != '\0')
    // {
    //     *dest++ = *src++;
    //     // dest++;
    //     // src++;
    // }
    // *dest = *src;
    // 优化版本，借助 '\0' 结束循环
    char *ret = dest;
    assert(dest != NULL); // 断言
    assert(src != NULL);  // 断言
    while (*dest++ = *src++)
    {
        ;
    }
    // if (dest != NULL && src != NULL)
    // {
    //     while (*dest++ = *src++)
    //     {
    //         ;
    //     }
    // }
    return ret;
}

int main()
{
    // 1.栈区的默认使用：先使用高地址处的空间，再使用低地址处的空间
    // 2.数组随着下标的增长，地址是由低到高变化

    int x = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%p\n", &x);  // 0x7ff7b8ec1078 低地址
    printf("%p\n", arr); // 0x7ff7b8ec1080 高地址，release版本优化过内存布局

    printf("\n");
    printf("---------------------\n");
    printf("\n");

    char arr1[] = "###################";
    char arr2[] = "bit";
    char *ret = my_strcpy(arr1, arr2);
    printf("%s\n", ret);

    const int num = 10;
    // 指针加上const，就不能被改变了
    // const 放在指针变量的 * 左边时（const int *p），修饰的是被指向的变量 *p ，也就是说：不能通过p来改变 *p(num) 的值
    // const 放在指针变量的 * 右边时（int * const p），修饰的是指针变量本身 p，就是说这个指针 p 不能指向其他变量的地址了
    const int *p = &num;
    // *p = 20;
    return 0;
}

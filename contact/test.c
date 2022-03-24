#include "contact.h"

void menu()
{
    printf("*************************************************\n");
    printf("************* 1.add      2.del    ***************\n");
    printf("************* 3.search   4.modify ***************\n");
    printf("************* 5.show     6.sort   ***************\n");
    printf("************* 7.save     0.exit   ****************\n");
    printf("**************************************************\n");
}

// gcc test.c  contact.c  -o test && test
int main()
{
    int input = 0;
    // 创建通讯录
    struct Contact con;
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:

            AddContact(&con);
            break;
        case DEL:

            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);

            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:

            ShowContact(&con);
            break;
        case SORT:

            break;
        case SAVE:
            SaveContact(&con);
            break;
        case EXIT:
            SaveContact(&con);
            DestoryContact(&con);
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);
    return 0;
}
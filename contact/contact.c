#include "contact.h"

// 因为 CheckCapactity 函数是在后面定义的，所以在这里声明一下
void CheckCapactity(Contact *ps);

void LoadContact(struct Contact *ps)
{
    FILE *pr = fopen("contact.dat", "rb");
    if (pr == NULL)
    {
        printf("LoadContact::%s\n", strerror(errno));
        return;
    }

    PeoInfo tmp = {0};
    while (fread(&tmp, sizeof(PeoInfo), 1, pr))
    {
        CheckCapactity(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }

    printf("加载成功\n");

    // 读取文件，存放到通讯录中
    fclose(pr);
    pr = NULL;
}

void InitContact(struct Contact *ps)
{
    // memset(ps->data, 0, sizeof(ps->data));
    ps->data = (PeoInfo *)malloc(DEFAULT_SZ * sizeof(PeoInfo));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0; // 设置通讯录最初只有0个元素
    ps->capcity = DEFAULT_SZ;
    LoadContact(ps);
}

void CheckCapactity(Contact *ps)
{
    if (ps->capcity == ps->size)
    {
        // 扩容
        PeoInfo *ptr = realloc(ps->data, (ps->capcity + 2) * sizeof(PeoInfo));
        if (ptr != NULL)
        {
            ps->data = ptr;
            ps->capcity += 2;
            printf("扩容成功\n");
        }
        else
        {
            printf("扩容失败\n");
        }
    }
}

void AddContact(struct Contact *ps)
{
    CheckCapactity(ps);

    printf("请输入名字:>");
    scanf("%s", ps->data[ps->size].name); // 数组，不需要取地址
    printf("请输入年龄:>");
    scanf("%d", &(ps->data[ps->size].age)); // int，要取地址
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址:>");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功\n");
    // if (ps->size > MAX)
    // {
    //     printf("通讯录已满,无法增加\n");
    // }
    // else
    // {
    //     printf("请输入名字:>");
    //     scanf("%s", ps->data[ps->size].name); // 数组，不需要取地址
    //     printf("请输入年龄:>");
    //     scanf("%d", &(ps->data[ps->size].age)); // int，要取地址
    //     printf("请输入性别:>");
    //     scanf("%s", ps->data[ps->size].sex);
    //     printf("请输入电话:>");
    //     scanf("%s", ps->data[ps->size].tele);
    //     printf("请输入地址:>");
    //     scanf("%s", ps->data[ps->size].addr);
    //     ps->size++;
    //     printf("添加成功\n");
    // }
}

void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-6s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

        for (int i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-6s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
    }
}

static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    // 1.查找要删除人的位置
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        // 2.删除数据
        for (int j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-6s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

        printf("%-20s\t%-4d\t%-6s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要修改的人不存在\n");
    }
    else
    {

        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name); // 数组，不需要取地址
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age)); // int，要取地址
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);
        printf("修改成功\n");
    }
}

void DestoryContact(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
}

void SaveContact(struct Contact *ps)
{
    FILE *pw = fopen("contact.dat", "wb");
    if (pw == NULL)
    {
        printf("SaveContact::%s\n", strerror(errno));
        return;
    }

    for (int i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pw);
    }
    printf("保存成功\n");

    fclose(pw);
    pw = NULL;
}

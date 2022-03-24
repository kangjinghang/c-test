#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
} PeoInfo;

// 通讯录类型
typedef struct Contact
{
    struct PeoInfo *data; // 存放信息
    int size;             // 记录当前已经有的元素个数
    int capcity;          // 当前通讯录的最大容量
} Contact;

enum Operation
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    SAVE
};

void InitContact(struct Contact *ps);
void AddContact(struct Contact *ps);
void ShowContact(const struct Contact *ps);
void DelContact(struct Contact *ps);
void SearchContact(const struct Contact *ps);
void ModifyContact(struct Contact *ps);
void DestoryContact(struct Contact *ps);
void SaveContact(struct Contact *ps);
void LoadContact(struct Contact *ps);

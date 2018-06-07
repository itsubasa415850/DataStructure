#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

typedef struct node
{
    string key;
    struct node* next;
}ListNode;

typedef ListNode* LinkList;

LinkList initList();
void insert(LinkList l, string key);
void delete1(LinkList l, string key);
void show(LinkList l);
LinkList reverse(LinkList l);

int main()
{
    char ch1,ch2;
    string data;
    ch1 = 'y';
    LinkList l;
    printf("生成一个以字符串单链表。\n");
    l = initList();
    while(ch1=='y' || ch1=='Y')
    {
        printf("请选择下列操作：\n");
        printf("A------------------将数据插入单链表\n");
        printf("B------------------从单链表中删除数据\n");
        printf("C------------------展示该单链表的内容\n");
        printf("D------------------反转该单链表\n");
        printf("Q------------------退出\n");
        scanf("\n%c",&ch2);
        switch (ch2)
        {
            case 'A':
            case 'a':
                printf("请输入要插入的字符串，以“@@@”作为结束标志：\n");
                data = (string) malloc(sizeof(string));
                scanf("%s", data);
                insert(l, data);
                break;
            case 'B':
            case 'b':
                printf("请输入要删除的字符串：\n");
                data = (string) malloc(sizeof(string));
                scanf("%s", data);
                delete1(l, data);
                break;
            case 'C':
            case 'c':
                show(l);
                break;
            case 'D':
            case 'd':
                l = reverse(l);
                show(l);
                break;
            case 'Q':
            case 'q':
                ch1='n';
                break;
            default:
                printf("输入有误，请重新输入。\n");
                printf("A------------------将数据插入单链表\n");
                printf("B------------------从单链表中删除数据\n");
                printf("C------------------展示该单链表的内容\n");
                break;
        }
    }
}

LinkList initList()
{
    LinkList l = (ListNode*) malloc(sizeof(ListNode*));
    l->key = "";
    l->next = NULL;
    string key = (string) malloc(sizeof(string));
    printf("请输入要插入的字符串，以“@@@”作为结束标志：\n");
    scanf("%s", key);
    while(1)
    {
        if(strcmp(key, "@@@") != 0)
        {
            insert(l, key);
            printf("请输入要插入的字符串，以“@@@”作为结束标志：\n");
            key = (string) malloc(sizeof(string));
            scanf("%s", key);
        }
        else
        {
            break;
        }
    }
    return l;
}

void insert(LinkList l, string key)
{
    ListNode* newNode;
    ListNode* rear;
    newNode = l;
    if(strcmp("", key) == 0)
    {
        printf("不允许空。\n");
        return;
    }
    while(newNode)
    {
        if(strcmp("", newNode->key) == 0)
        {
            l->key = key;
            return;
        }
        if(strcmp(key, newNode->key) == 0)
        {
            printf("输入的字符串已经存在，不需要再插入。\n");
            return;
        }
        rear = newNode;
        newNode = newNode->next;
    }
    newNode = (ListNode*) malloc(sizeof(ListNode*));
    newNode->key = key;
    newNode->next = NULL;
    rear->next = newNode;
}

void delete1(LinkList l, string key)
{
    ListNode* prev;
    ListNode* target;
    //初始化，前一个节点即为表头
    prev = l;
    //表头即为对象节点时
    if(strcmp(key, prev->key) == 0)
    {
        l = l->next;
        target = prev;
        target->next = NULL;
    }
    
    while(prev->next)
    {
        target = prev->next;
        if(strcmp(key, target->key) == 0)
        {
            //将对象节点从链表上摘除
            prev->next = target->next;
            target->next = NULL;
            break;
        }
        else
        {
            prev = prev->next;
        }
    }
    if(prev != target)
    {
        free(target);
        return;
    }
    printf("目前没有可以删除的节点。\n");
}

LinkList reverse(LinkList l)
{
    ListNode* next;
    ListNode* prev;
    ListNode* curr;
    curr = prev = l;
    next = l->next;
    while(curr)
    {
        if(curr == l)
        {
            //链头节点变成尾节点
            prev->next = NULL;
        }
        else
        {
            //直接后继变成直接前趋
            curr->next = prev;
        }
        prev = curr;
        if(curr)
        {
            l = curr;
        }
        curr = next;
        if(next)
        {
            next = next->next;
        }
    }
    prev = NULL;
    return l;
}

void show(LinkList l)
{
    if(l)
    {
        printf("%s\t", l->key);
        show(l->next);
    }
}

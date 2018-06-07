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
    printf("����һ�����ַ���������\n");
    l = initList();
    while(ch1=='y' || ch1=='Y')
    {
        printf("��ѡ�����в�����\n");
        printf("A------------------�����ݲ��뵥����\n");
        printf("B------------------�ӵ�������ɾ������\n");
        printf("C------------------չʾ�õ����������\n");
        printf("D------------------��ת�õ�����\n");
        printf("Q------------------�˳�\n");
        scanf("\n%c",&ch2);
        switch (ch2)
        {
            case 'A':
            case 'a':
                printf("������Ҫ������ַ������ԡ�@@@����Ϊ������־��\n");
                data = (string) malloc(sizeof(string));
                scanf("%s", data);
                insert(l, data);
                break;
            case 'B':
            case 'b':
                printf("������Ҫɾ�����ַ�����\n");
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
                printf("�����������������롣\n");
                printf("A------------------�����ݲ��뵥����\n");
                printf("B------------------�ӵ�������ɾ������\n");
                printf("C------------------չʾ�õ����������\n");
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
    printf("������Ҫ������ַ������ԡ�@@@����Ϊ������־��\n");
    scanf("%s", key);
    while(1)
    {
        if(strcmp(key, "@@@") != 0)
        {
            insert(l, key);
            printf("������Ҫ������ַ������ԡ�@@@����Ϊ������־��\n");
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
        printf("������ա�\n");
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
            printf("������ַ����Ѿ����ڣ�����Ҫ�ٲ��롣\n");
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
    //��ʼ����ǰһ���ڵ㼴Ϊ��ͷ
    prev = l;
    //��ͷ��Ϊ����ڵ�ʱ
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
            //������ڵ��������ժ��
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
    printf("Ŀǰû�п���ɾ���Ľڵ㡣\n");
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
            //��ͷ�ڵ���β�ڵ�
            prev->next = NULL;
        }
        else
        {
            //ֱ�Ӻ�̱��ֱ��ǰ��
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

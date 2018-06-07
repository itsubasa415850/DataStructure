#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*********************������**********************/
typedef char digit;

typedef struct node
{
    //Ԫ��
    digit data;
    //��һ��ָ��
    struct node* next;
    //ջ��ָ��
    struct node* buttom;
}StackNode;

typedef StackNode* Stack;

Stack initStack();
//��ջ
Stack push(Stack, digit);
//��ջ
digit pop(Stack);
//չʾ+��ջ
void show(Stack);
//��չʾ
void showOnly(Stack);
//ת������������Ϊ��ջ��Ŀ���������ơ�����
void transform(Stack, int, int, char*);
/*************************************************/

int main()
{
    char table[16] = {'0','1','2','3','4',
    '5','6','7','8','9','a',
    'b','c','d','e','f',};
    int target;
    Stack stack = initStack();
    printf("ʹ�ö�ջʵ�����Ƶ�ת����\n");
    printf("��������ʾ��10������ת��Ϊ2����8����16����ջ�������̡�\n");
    while(1)
    {
        printf("������һ��10��������������0����ֹ��\n");
        scanf("%d", &target);
        if(target == 0)
        {
            return;
        }
        printf("%dת��Ϊ2�������Ľ��Ϊ��", target);
        transform(stack, target, 2, table);
        printf("\n");
        printf("%dת��Ϊ8�������Ľ��Ϊ��", target);
        transform(stack, target, 8, table);
        printf("\n");
        printf("%dת��Ϊ16�������Ľ��Ϊ��", target);
        transform(stack, target, 16, table);
        printf("\n");
    }
    
}

Stack initStack()
{
    Stack stack = (Stack) malloc(sizeof(Stack));
    stack->data = '^';
    stack->next = NULL;
    stack->buttom = stack;
    return stack;
}

Stack push(Stack s, digit data)
{
    //�½ڵ����ռ�
    StackNode* n =(StackNode*) malloc(sizeof(StackNode*));
    //�½ڵ㸳ֵ
    n->data = data;
    //�½ڵ����ջ��
    n->next = s;
    //�½ڵ��ջ��ָ���ÿ�
    n->buttom = NULL;
    //ջ��ָ���½ڵ�
    s = n;
    return s;
}

digit pop(Stack s)
{
    StackNode* target = s;
    //ȡֵ
    digit value = target->data;
    //Ŀ��ڵ�ָ���ÿ�
    target->next = NULL;
    //ջ������
    s = s->next;
    //�ͷſռ�
    free(target);
    return value;
}

void show(Stack s)
{
    while(s->buttom)
    {
        printf("%c", s->data);
        pop(s);
    }
}

void showOnly(Stack s)
{
    if(!s->buttom)
    {
        printf("%c", s->data);
        showOnly(s->next);
    }
}

void transform(Stack s, int target, int radix, char* table)
{
    int remainder;
    if(target < radix)
    {
        s = push(s, table[target]);
    }
    else
    {
        while(target)
        {
            remainder = target % radix;
            s = push(s, table[remainder]);
            if(!remainder)
            {
                target /= radix;
            }
            else
            {
                target = (target - remainder) / radix;
            }
        }
    }
    showOnly(s);
}

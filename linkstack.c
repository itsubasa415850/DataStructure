#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*********************声明部**********************/
typedef char digit;

typedef struct node
{
    //元素
    digit data;
    //下一个指针
    struct node* next;
    //栈底指针
    struct node* buttom;
}StackNode;

typedef StackNode* Stack;

Stack initStack();
//入栈
Stack push(Stack, digit);
//出栈
digit pop(Stack);
//展示+清栈
void show(Stack);
//纯展示
void showOnly(Stack);
//转换，参数依次为：栈、目标数、进制、数表
void transform(Stack, int, int, char*);
/*************************************************/

int main()
{
    char table[16] = {'0','1','2','3','4',
    '5','6','7','8','9','a',
    'b','c','d','e','f',};
    int target;
    Stack stack = initStack();
    printf("使用堆栈实现数制的转化。\n");
    printf("本程序演示将10进制数转化为2进、8进和16进的栈操作流程。\n");
    while(1)
    {
        printf("请输入一个10进制数，若输入0则终止。\n");
        scanf("%d", &target);
        if(target == 0)
        {
            return;
        }
        printf("%d转换为2进制数的结果为：", target);
        transform(stack, target, 2, table);
        printf("\n");
        printf("%d转换为8进制数的结果为：", target);
        transform(stack, target, 8, table);
        printf("\n");
        printf("%d转换为16进制数的结果为：", target);
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
    //新节点分配空间
    StackNode* n =(StackNode*) malloc(sizeof(StackNode*));
    //新节点赋值
    n->data = data;
    //新节点接入栈体
    n->next = s;
    //新节点的栈底指针置空
    n->buttom = NULL;
    //栈顶指向新节点
    s = n;
    return s;
}

digit pop(Stack s)
{
    StackNode* target = s;
    //取值
    digit value = target->data;
    //目标节点指针置空
    target->next = NULL;
    //栈顶下移
    s = s->next;
    //释放空间
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

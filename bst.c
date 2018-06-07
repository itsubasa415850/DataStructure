#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct node
{
    KeyType key;
    struct node *lchild,*rchild;
}BSTNode;

typedef BSTNode* BSTree;

BSTree CreateBST(void);
void InsertBST(BSTree *Tptr,KeyType Key);
void DelBSTNode(BSTree *Tptr,KeyType Key);
void InorderBST(BSTree T);


void InsertBST(BSTree *T,KeyType Key)
{
    BSTNode *f,*p;
    p = *T;
    while(p)
    {
        if(p->key == Key)
        {
            printf("树中已有Key不需插入\n");
            return;
        }
        f=p;
        p=(Key<p->key)?p->lchild:p->rchild;
    }
    p=(BSTNode*)malloc(sizeof(BSTNode));
    p->key=Key;
    p->lchild=p->rchild=NULL;
    if ((*T)==NULL)
    {
        (*T)=p;
    }
    else if(Key < f->key)
    {
        f->lchild = p;
    }
    else
    {
        f->rchild = p;
    }
}

BSTree CreateBST()
{
    BSTree T;
    KeyType Key;
    T=NULL;
    printf("请输入一个关键字(输入0时结束输入)：\n");
    scanf("%d",&Key);
    while (Key)
    {
        InsertBST(&T, Key);
        printf("请输入下一个关键字(输入0时结束输入)：\n");
        scanf("\n%d",&Key);
    }
    return T;
}

void InorderBST(BSTree T)
{
    if(T)
    {
        InorderBST(T->lchild);
        printf("%5d",T->key);
        InorderBST(T->rchild);
    }
}

void DelBSTNode(BSTree *T,KeyType Key)
{
    BSTNode *parent=NULL, *p, *q,*child;
    p=*T;
    while(p)
    {
        if(p->key == Key)
        {
            break;
        }
        parent=p;
        //填写2
        p = (Key > p->key) ? p->rchild : p->lchild;
    }
    if(!p)
    {
        printf("没有找到要删除的结点\n");
        return;
    }
    q=p;
    //这句话的意思就是q的左右子树都不为“空”、都不为“空”、都不为“空”！！！！！！！！
    if (q->lchild && q->rchild)
    {
        for (parent=q,p=q->rchild; p->lchild; parent=p,p=p->lchild);//相当于循环体是空的
        /*
        {
            //只循环，没有操作，变量的值一直在变。
        }
        */
    }

    child=(p->lchild)?p->lchild:p->rchild;
    if(!parent)
    {
        *T=child;
    }
    else
    {
        if(parent->lchild == p)
        {
            parent->lchild = child;
        }
        else
        {
            parent->rchild = child;
        }
        if (p!=q)
        {
            q->key=p->key;
        }
    }
	free(p);
}


int main()
{
    BSTree T;
    char ch1,ch2;
    KeyType Key;
    printf("建立一棵二叉排序树的二叉链表存储\n");
    T=CreateBST();
    ch1='y';
    while (ch1=='y' || ch1=='Y')
    {
        printf("请选择下列操作：\n");
        printf("A------------------更新二叉排序树存储\n");
        printf("B------------------二叉排序树上的删除\n");
        printf("C------------------二叉排序树中序输出\n");
        printf("D------------------退出\n");
        scanf("\n%c",&ch2);
        switch (ch2)
        {
            case 'A':
            case 'a':
                printf("请输入一个关键字(输入0时结束输入)：\n");
                scanf("%d",&Key);
                InsertBST(&T, Key);
                break;
            case 'B':
            case 'b':
                printf("\n请输入要删除的数据：");
                scanf("\n%d",&Key);
                DelBSTNode(&T,Key);
                printf("删除操作完毕。\n");
                break;
            case 'C':
            case 'c':
                InorderBST(T);
                printf("\n二叉排序树输出完毕。\n");
                break;
            case 'D':
            case 'd':
                ch1='n';
                break;
            default:
                ch1='n';
        }
    }

}

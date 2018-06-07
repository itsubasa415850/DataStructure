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
            printf("��������Key�������\n");
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
    printf("������һ���ؼ���(����0ʱ��������)��\n");
    scanf("%d",&Key);
    while (Key)
    {
        InsertBST(&T, Key);
        printf("��������һ���ؼ���(����0ʱ��������)��\n");
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
        //��д2
        p = (Key > p->key) ? p->rchild : p->lchild;
    }
    if(!p)
    {
        printf("û���ҵ�Ҫɾ���Ľ��\n");
        return;
    }
    q=p;
    //��仰����˼����q��������������Ϊ���ա�������Ϊ���ա�������Ϊ���ա�����������������
    if (q->lchild && q->rchild)
    {
        for (parent=q,p=q->rchild; p->lchild; parent=p,p=p->lchild);//�൱��ѭ�����ǿյ�
        /*
        {
            //ֻѭ����û�в�����������ֵһֱ�ڱ䡣
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
    printf("����һ�ö����������Ķ�������洢\n");
    T=CreateBST();
    ch1='y';
    while (ch1=='y' || ch1=='Y')
    {
        printf("��ѡ�����в�����\n");
        printf("A------------------���¶����������洢\n");
        printf("B------------------�����������ϵ�ɾ��\n");
        printf("C------------------�����������������\n");
        printf("D------------------�˳�\n");
        scanf("\n%c",&ch2);
        switch (ch2)
        {
            case 'A':
            case 'a':
                printf("������һ���ؼ���(����0ʱ��������)��\n");
                scanf("%d",&Key);
                InsertBST(&T, Key);
                break;
            case 'B':
            case 'b':
                printf("\n������Ҫɾ�������ݣ�");
                scanf("\n%d",&Key);
                DelBSTNode(&T,Key);
                printf("ɾ��������ϡ�\n");
                break;
            case 'C':
            case 'c':
                InorderBST(T);
                printf("\n���������������ϡ�\n");
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

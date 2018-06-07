#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define INITSIZE 8
typedef int DATATYPE;
typedef struct SequentialList *SqList;

struct SequentialList
{
	DATATYPE data[MAXSIZE];
	DATATYPE last;
} L;

SqList initList()
{
	SqList list = (SqList) malloc(sizeof(SqList));
	list->last = -1;
	return list;
}

void insert(DATATYPE X, SqList list)
{
	DATATYPE idx;
	DATATYPE target;
	for(idx = list->last - 1; idx >= 0; idx--)
	{
		if(X == list->data[idx])
		{
			printf("重复数据不插入。");
		}
		if(X > list->data[idx])
		{
			continue;
		}
		else
		{
			target = idx + 1;
			for(idx = list->last; idx >= target; idx--)
			{
				list->data[idx] = list->data[idx - 1];
			}
			list->data[target] = X;
			list->last = list->last + 1;
			break;
		}
	}
}

void delete(DATATYPE target, SqList list)
{
	DATATYPE idx;
	DATATYPE targetIndex;
	for(idx = list->last - 1; idx >= 0; idx--)
	{
	    if(list->data[idx] == target)
	    {
	        for(; idx < list->last - 1; idx ++)
	        {
	            list->data[idx] = list->data[idx + 1];
            }
            list->last = list->last - 1;
	        break;
        }
    }
    
	for(idx = 0; idx < list->last; idx ++)
	{
		printf("第%d个位置的值是：%d。\n", idx, list->data[idx]);
	}
}

void destructList(SqList list)
{
	free(list);
}

int main() 
{
	/*
	SqList list;
	DATATYPE x;
	DATATYPE pos;
	DATATYPE option;
	printf("线性表演示程序\n");
	for(;;)
	{
		printf("请输入以演示功能：\n");
		printf("1.初始化一个线性表\n");
		printf("2.插入一个元素\n");
		printf("3.删除一个元素\n");
		printf("4.删除线性表\n");
		printf("99.退出\n");
		printf("你的选择：\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				fflush(stdin);
				printf("请输入初始化大小：\n");
				scanf("%d", x);
				list = initList(x);
				if(list == NULL)
				{
					printf("初始化失败，请重新初始化。\n");
				}
				continue;
			case 2:
				printf("请输入要插入的数据：");
				scanf("%d", x);
				printf("请输入要插入的位置：");
				scanf("%d", pos);
				insert(x, pos, list);
				continue;
			case 3:
				printf("请输入要删除的数据所在位置：");
				scanf("%d", pos);
				delete(pos, list);
				continue;
			case 4:
				destructList(list);
				continue;
			case 99:
				system("pause");
				return;
			default:
				printf("输入错误。请重新输入：");
				fflush(stdin);
				continue;
		}
	}
	*/
	DATATYPE i;
	SqList list;
	list = initList();
	printf("请按递减序输入%d个整数(以空格为间隔):\n",INITSIZE);	
	for(i = 0; i < INITSIZE; i++)
	{
		scanf("%d", &list->data[i]);
	}
	list->last = INITSIZE;
	
//	insert(57, list);
//	insert(5, list);
//	insert(18, list);
	delete(48, list);
//	destructList(list);
}


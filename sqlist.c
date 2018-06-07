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
			printf("�ظ����ݲ����롣");
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
		printf("��%d��λ�õ�ֵ�ǣ�%d��\n", idx, list->data[idx]);
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
	printf("���Ա���ʾ����\n");
	for(;;)
	{
		printf("����������ʾ���ܣ�\n");
		printf("1.��ʼ��һ�����Ա�\n");
		printf("2.����һ��Ԫ��\n");
		printf("3.ɾ��һ��Ԫ��\n");
		printf("4.ɾ�����Ա�\n");
		printf("99.�˳�\n");
		printf("���ѡ��\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				fflush(stdin);
				printf("�������ʼ����С��\n");
				scanf("%d", x);
				list = initList(x);
				if(list == NULL)
				{
					printf("��ʼ��ʧ�ܣ������³�ʼ����\n");
				}
				continue;
			case 2:
				printf("������Ҫ��������ݣ�");
				scanf("%d", x);
				printf("������Ҫ�����λ�ã�");
				scanf("%d", pos);
				insert(x, pos, list);
				continue;
			case 3:
				printf("������Ҫɾ������������λ�ã�");
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
				printf("����������������룺");
				fflush(stdin);
				continue;
		}
	}
	*/
	DATATYPE i;
	SqList list;
	list = initList();
	printf("�밴�ݼ�������%d������(�Կո�Ϊ���):\n",INITSIZE);	
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


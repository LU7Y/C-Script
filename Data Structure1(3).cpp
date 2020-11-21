/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define ListLength 5

typedef struct Test
{
	int data;
	int freq;
	struct Test* next;
	struct Test* prior;
}List;

void OutputList(List*& L)
{
	List* head = L;
	L = L->next;
	printf("{ ");
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("}\n");
	L = head;
}

void CreateList(List*& L)
{
	L = new List;
	L->next = NULL;
	L->prior = NULL;
	List* head = L;
	for (int i = 0; i < ListLength; i++)
	{
		List* L1 = new List;
		L1->freq = 0;
		L1->data = i + 1;
		L1->next = NULL;
		L1->prior = L;
		L->next = L1;
		L = L->next;
	}
	L = head;
	printf("链表创建成功! \n");
	OutputList(L);
}

void ListSort(List*& L, List*& head)
{
	if (L->prior == head)
	{
		return;
	}
	List* before;
	while (L->prior != NULL)
	{
		if (L->prior == head)
		{
			break;
		}
		before = L->prior;
		if (L->freq > before->freq)
		{
			before->next = L->next;
			if (L->next != NULL)
			{
				before->next->prior = before;
			}
			L->next = before;
			L->prior = before->prior;
			before->prior->next = L;
			before->prior = L;
			continue;	
		}
		else
		{
			break;
		}
	}
	L = head;
}

void LocateNode(List*& L, int  x)
{
	int find = 0;
	List* head = L;
	L = L->next;
	while (L != NULL)
	{
		if (L->data == x)
		{
			find = 1;
			break;
		}
		L = L->next;
	}
	if (find == 0)
	{
		printf("未找到该结点!\n");
		return;
	}
	else
	{
		printf("找到结点【data=%d】!\n", L->data);
	}
	L->freq++;
	ListSort(L, head);
	L = head;
	OutputList(L);
}

int main()
{
	int checknum;
	List* testl;
	CreateList(testl);
	while (1)
	{
		printf("请输要查找的数:");
		scanf("%d", &checknum);
		LocateNode(testl, checknum);
	}
	return 0;
}
*/
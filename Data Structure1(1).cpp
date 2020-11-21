/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define InitListLength 5

typedef struct Test
{
	int data;
	struct Test* next;
}List;

void ListInit(List*& L)
{
	L = new List;
	L->next = NULL;
	List* L1 = L;
	List* L2;
	for (int i = 0, j = 0; i < InitListLength; i++, j += 2)
	{
		L2 = new List;
		L2->data = j;
		L2->next = NULL;
		L->next = L2;
		L = L->next;
	}
	L = L1;
	L = L->next;
	L2->next = L;
	printf("链表创建完成!\n");
}

void ListOutput(List* L)

{
	List* L2 = L;
	printf("{");
	while (L2->next->data != L->data)
	{
		printf(" %d", L2->data);
		L2 = L2->next;
	}
	printf(" %d }\n", L2->data);
}

void DeletePoint(List*& L, List* S)
{
	List* before = L, * after = L;

	while (before->next->next->data != S->data)
	{
		before = before->next;
	}
	while (after->next->data != S->data)
	{
		after = after->next;
	}
	if (after == L)
	{
		before->next = L->next;
		L = before->next;
		return;
	}
	before->next = after->next;
	delete after;
}

int main()
{
	List* testl, * t = new List;
	ListInit(testl);
	ListOutput(testl);

	printf("请输入要删除的数据:");
	scanf("%d", &t->data);
	
	DeletePoint(testl, t);
	ListOutput(testl);
	return 0;
}
*/
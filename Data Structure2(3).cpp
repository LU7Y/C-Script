/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXSIZE 100
#define INITCOUNT 5

typedef struct Test
{
	int data;
	struct Test* next;
	struct Test* rear;
}Node;

int IsQueueEmpty(Node*& L)
{
	if (L->rear->next == L->rear)
	{
		return 1;
	}
	return 0;
}

void CreateQueue(Node*& L)
{
	L = new Node;
	L->next = NULL;
	Node* L1 = L;
	for (int i = 0; i < INITCOUNT; i++)
	{
		Node* L2 = new Node;
		L2->data = i+1;
		L2->next = L;
		L1->next = L2;
		L1 = L2;
		L->rear = L2;
	}
}

void Output(Node*& L)
{
	if (IsQueueEmpty(L))
	{
		printf("队列为空！\n");
	}
	Node* head = L;
	L = L->next;
	while (L!=head)
	{
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\n");
	L = head;
}

void InitQueue(Node*& L)
{
	Node* L1;
	L->rear= L->rear->next;
	while (!IsQueueEmpty(L))
	{
		L1 = L->rear->next;
		L->rear->next = L1->next;
		delete L1;
	}
	printf("队列置空！\n");
}


void InQueue(Node* L, int x)
{
	Node* L1 = new Node;
	L1->data = x;
	L1->next = L;
	L->rear->next = L1;
	L->rear = L1;
	return;
}

void OutQueue(Node*& L,int& x)
{
	Node* L1;
	if (IsQueueEmpty(L))
	{
		printf("队列为空！\n");
		return;
	}
	L1 = L->next;
	x = L1->data;
	L->next = L1->next;
	return;
}

int main()
{
	Node* L;
	int x;
	CreateQueue(L);
	Output(L);
	InQueue(L, 6);
	Output(L);
	OutQueue(L,x);
	Output(L);
	InitQueue(L);
	Output(L);
	return 0;
}
*/
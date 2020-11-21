/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXSIZE 100

typedef struct SK
{
	char* base;
	char* top;
}Stack;

typedef struct Data
{
	char data;
	struct Data* next;
}Node;

void InitList(Node*& L, int count)
{
	L = new Node;
	L->next = NULL;
	Node* head = L;
	getchar();
	for (int i = 0; i < count; i++)
	{
		Node* L1 = new Node;
		scanf("%c", &L1->data);
		getchar();
		L1->next = NULL;
		L->next = L1;
		L = L->next;
	}
	L = head;
	return;
}

void InitStack(Stack& S)
{
	S.base = new char[MAXSIZE];
	if (S.base == NULL)
	{
		printf("内存分配失败!\n");
		exit(0);
	}
	S.top = S.base;
	return;
}

void PushIntoStack(Stack& S, Node*& L)
{
	Node* head = L;
	L = L->next;
	while (L != NULL)
	{
		*S.top = L->data;
		L = L->next;
		S.top++;
	}
	S.top--;
	L = head;
	return;
}

int Judge(Stack& S, Node*& L)
{
	int i = 1;
	Node* head = L;
	L = L->next;
	while (L != NULL)
	{
		if (*S.top == L->data)
		{
			S.top--;
			L = L->next;
			continue;
		}
		else
		{
			i = 0;
			break;
		}
	}
	return i;
}

int main()
{
	int count;
	int final;
	Stack S;
	Node* L;

	printf("请输入要所输字符个数: ");
	scanf("%d", &count);

	InitList(L, count);
	InitStack(S);
	PushIntoStack(S, L);
	final = Judge(S, L);
	printf("%d", final);
	return 0;
}
 */
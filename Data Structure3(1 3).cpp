/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TR
{
	char data;
	char pos;
	struct TR* Lchild, * Rchild;
}Tree;

typedef struct ST
{
	Tree* base;
	Tree* top;
}Stack;

void InitStack(Stack& S)
{
	S.base = new Tree[MAXSIZE];
	if (S.base == NULL)
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	S.top = S.base;
	return;
}

bool IsStackEmpty(Stack& S)
{
	if (S.base == S.top)
	{
		return true;
	}
	return false;
}

void PushIntoStack(Stack& S, Tree*& T)
{
	*(S.top) = *T;
	S.top++;
	return;
}

void PopFromStack(Stack& S, Tree*& T)
{
	if (IsStackEmpty(S))
	{
		return;
	}
	S.top--;
	*T = *(S.top);
	return;
}

bool GetStackTop(Stack& S, Tree*& T)
{
	if (IsStackEmpty(S))
	{
		printf("栈空！\n");
		return false;
	}
	*T = *(S.top - 1);
	return true;
}

void CreateTree(Tree*& T)
{
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new Tree;
		T->data = ch;
		CreateTree(T->Lchild);
		CreateTree(T->Rchild);
	}
}

int Depth(Tree*& T)
{
	int n, m;
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->Lchild);
		n = Depth(T->Rchild);
		if (m > n)
		{
			return (m + 1);
		}
		else
		{
			return (n + 1);
		}
	}
}

void PreForsearch(Tree*& T)
{
	if (T == NULL)
	{
		return;
	}
	Stack S;
	InitStack(S);
	Tree* pt = T, * top = new Tree;
	while (pt != NULL || !IsStackEmpty(S))
	{
		if (pt != NULL)
		{
			printf("%c ",pt->data);
			PushIntoStack(S, pt);
			pt = pt->Lchild;
		}
		else
		{
			PopFromStack(S, top);
			pt = top->Rchild;
		}
	}
	printf("\n");
}

void MidForsearch(Tree*& T)
{
	if (T == NULL)
	{
		return;
	}
	Stack S;
	InitStack(S);
	Tree* pt = T, * top = new Tree;
	while (pt != NULL || !IsStackEmpty(S))
	{
		if (pt != NULL)
		{
			PushIntoStack(S, pt);
			pt = pt->Lchild;
		}
		else
		{
			PopFromStack(S, top);
			printf("%c ", top->data);
			pt = top->Rchild;
		}
	}
	printf("\n");
}

void AfterForsearch(Tree*& T)
{
	if (T == NULL)
	{
		return;
	}
	Stack S;
	InitStack(S);
	Tree* pt = T, * top = new Tree;
	while (!IsStackEmpty(S) || pt)
	{
		while (pt != NULL)
		{
			pt->pos = 'l';
			PushIntoStack(S, pt);
			pt = pt->Lchild;
		}
		//GetStackTop(S, top);
		//printf("%c" ,top->data);
		PopFromStack(S, top);
		if (top->pos == 'l')
		{
			top->pos = 'r';
			PushIntoStack(S, top);
			pt = top;
			pt = pt->Rchild;
		}
		else
		{
			printf("%c ",top->data);
		}
	}
	printf("\n");
}

int main()
{
	Tree* T;
	int depth;
	CreateTree(T);
	depth = Depth(T);
	printf("二叉树深度为: %d\n", depth);
	PreForsearch(T);
	MidForsearch(T);
	AfterForsearch(T);
	return 0;
}
*/
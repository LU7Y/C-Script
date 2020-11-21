/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXSIZE 100

typedef struct SK
{
	char* top;
	char* base;
}Stack;

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

void PushIntoStack(Stack& S,char c)
{
	S.top++;
	*S.top = c;
	return;
}

char PopFromStack(Stack& S)
{
	char c = *S.top;
	S.top--;
	return c;
}

int IsStackEmpty(Stack& S)
{
	if (S.top == S.base)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsStackFull(Stack& S)
{
	if (*S.top == MAXSIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Judge(Stack& S)
{
	char c;
	printf("请输入一段表达式: ");
	while ((c = getchar()) != '\n')
	{
		if (c == '(')
		{
			PushIntoStack(S,c);
		}
		if (c == ')')
		{
			PopFromStack(S);
		}
	}
	if (IsStackEmpty(S) == 1)
	{
		printf("匹配!\n");
		return;
	}
	printf("不匹配!\n");
	return;
}

int main()
{
	Stack S;
	InitStack(S);
	Judge(S);
	return 0;
}
*/

//(7+8)*5+(
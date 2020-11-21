/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define InitListLength 5

typedef struct Test
{
	char data;
	struct Test* next;
}List;

void OutputList(List*& L)
{
	List* L2 = L;
	L2 = L2->next;
	printf("初始表:");
	printf("{");
	while (L2->next != NULL)
	{
		printf(" \'%c\' ", L2->data);
		L2 = L2->next;
	}
	printf(" \'%c\' }\n", L2->data);
}

void OutputCircleList(List*& L,int length)
{
	List* head = L;
	int count;
	printf("{");
	for (count = 0; count < length; count++)
	{
		printf(" \'%c\' ",L->data);
		L = L->next;
	}
	printf("}\n");
	L = head;
}

void ListInit(List*& L)
{
	L = new List;
	L->next = NULL;
	List* L1 = L;
	List* L2;
	printf("请输入%d个字符:",InitListLength);
	for (int i = 0; i < InitListLength; i++)
	{
		L2 = new List;
		scanf("%c", &L2->data);
		getchar();
		L2->next = NULL;
		L->next = L2;
		L = L->next;
	}
	L = L1;
}

void ListNullInit(List*& A, List*& B, List*& C)
{
	A = new List;
	A->next = NULL;
	B = new List;
	B->next = NULL;
	C = new List;
	C->next = NULL;
}

void ListSort(List*& L, List*& A, List*& B, List*& C, int& Alength, int& Blength, int& Clength)
{
	List* Lhead = L, * Ahead = A, * Bhead = B, * Chead = C;
	L = L->next;
	while (L != NULL)
	{
		List* newp = new List;
		newp->next = NULL;
		if (((L->data) >= 'a' && (L->data) <= 'z') || ((L->data) >= 'A' && (L->data) <= 'Z'))
		{
			newp->data = L->data;
			A->next = newp;
			A = A->next;
			Alength++;
		}
		else if ((L->data) >= '0' && (L->data) <= '9')
		{
			newp->data = L->data;
			B->next = newp;
			B = B->next;
			Blength++;
		}
		else
		{
			newp->data = L->data;
			C->next = newp;
			C = C->next;
			Clength++;
		}
		L = L->next;
	};
	A->next = Ahead->next;
	B->next = Bhead->next;
	C->next = Chead->next;
	A = Ahead->next;
	B = Bhead->next;
	C = Chead->next;
	L = Lhead;
}

int main()
{
	int Alength = 0, Blength = 0, Clength = 0;
	List* testl, * testl1, * testl2, * testl3;
	ListInit(testl);
	ListNullInit(testl1, testl2, testl3);
	OutputList(testl);
	ListSort(testl, testl1, testl2, testl3, Alength, Blength, Clength);
	printf("数字表:");
	OutputCircleList(testl1, Alength);
	printf("字母表:");
	OutputCircleList(testl2, Blength);
	printf("其它字符表:");
	OutputCircleList(testl3, Clength);
	return 0;
}
*/
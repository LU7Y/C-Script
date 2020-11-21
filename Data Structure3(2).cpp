/*
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define INITTREE 12

int main()
{
	int pos = 0, count = 1;
	char Tree[INITTREE];
	for (int i = 0; i < INITTREE; i++)
	{
		Tree[i] = 'A' + i;
	}
	while (!(count == 1 && pos == 2))
	{
		if (pos == 0)
		{
			printf("%c ", Tree[count - 1]);
			if (count * 2 > INITTREE)
			{
				pos = 1;
			}
			else
			{
				count = count * 2;
			}
		}

		else if (pos == 1)
		{
			if (count * 2 + 1 > INITTREE)
			{
				pos = 2;
			}
			else
			{
				count = count * 2 + 1;
				pos = 0;
			}
		}
		else if (pos == 2)
		{
			if (count % 2 == 0)
			{
				pos = 1;
			}
			else
			{
				pos = 2;
			}
			count = count / 2;
		}
	}
	return 0;
}
*/
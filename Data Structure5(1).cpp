
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<stack>
using namespace std;

#define MAX_VALUE 32767
#define MAX_VEXS 100
stack<int> Stack;
typedef struct AMGraph
{
	char vexs[MAX_VEXS];
	int arcs[MAX_VEXS][MAX_VEXS];
	int vexNum, arcNum;
}AMGraph;
bool isVisited[MAX_VEXS] = {false};
bool isFound=false;
int vexBesideLocation;
char GraphPath[MAX_VEXS];
//int rear = 0;
char  output[100];
void CreateGraph(AMGraph& G)
{
	printf("请输入总顶点数:");
	scanf("%d", &G.vexNum);
	printf("请输入总边数:");
	scanf("%d", &G.arcNum);
	getchar();
	for (int i = 0; i < G.vexNum; i++)
	{
		printf("请输入顶点(%d):", i + 1);
		scanf("%c", &G.vexs[i]);
		getchar();
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.arcNum; j++)
		{
			G.arcs[i][j] = MAX_VALUE;
		}
	}
	for (int i = 0; i < G.arcNum; i++)
	{
		char vex1, vex2;
		int vex1Location, vex2Location, arcValue;
		printf("请输入要连接的两个顶点:");
		scanf("%c %c", &vex1, &vex2);
		getchar();
		for (int j = 0; j < G.vexNum; j++)
		{
			if (vex1 == G.vexs[j])
			{
				vex1Location = j;
			}
			if (vex2 == G.vexs[j])
			{
				vex2Location = j;
			}
		}
		G.arcs[vex1Location][vex2Location] = 1;
		G.arcs[vex2Location][vex1Location] = 1;
	}
	printf("邻接矩阵初始化成功!\n");
}
int FirstAdjVex(AMGraph& G, int vexLocation)
{
	int i;
	for (i = 0; i < G.vexNum; i++)
	{
		if (G.arcs[vexLocation][i] == 1)
		{
			return i;
		}
	}
	if (i == (G.vexNum - 1))
	{
		return -1;
	}
	return -1;
}

int NextAdjVex(AMGraph& G, int vexLocation, int beforeLocation)
{
	int i;
	for (i = beforeLocation + 1; i < G.vexNum; i++)
	{
		if (G.arcs[vexLocation][i] == 1)
		{
			return i;
		}
	}
	if (i == (G.vexNum - 1))
	{
		return -1;
	}
	return -1;
}

void DFS(AMGraph& G, int vexBeginLocation, int vexEndLocation)
{
	if (isFound == true)
	{
		return;
	}
	isVisited[vexBeginLocation] = true;
	Stack.push(vexBeginLocation);
	if (vexBeginLocation == vexEndLocation)
	{
		isFound = true;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		if (isVisited[i]==false && G.arcs[vexBeginLocation][i] == 1)
		{
			DFS(G,i,vexEndLocation);
			if (isFound == false)
			{
				Stack.pop();
			}
		}
	}
}
/*
int main()
{
	AMGraph G;
	CreateGraph(G);
	char vexBegin, vexEnd;
	int vexBeginLocation, vexEndLocation;
	printf("请输入起点和终点:");
	scanf("%c %c", &vexBegin, &vexEnd);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (vexBegin == G.vexs[i])
		{
			vexBeginLocation = i;
		}
		if (vexEnd == G.vexs[i])
		{
			vexEndLocation = i;
		}
	}
	DFS(G, vexBeginLocation, vexEndLocation);
	int i = 0;
	while (!Stack.empty())
	{
		int a = Stack.top();
		output[i++] = G.vexs[a];
		Stack.pop();
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c ", output[j]);
	}
	//PrintPath();
}
*/
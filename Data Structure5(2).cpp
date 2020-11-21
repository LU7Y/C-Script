#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define MVNum 20

char push[MVNum];
bool visited[MVNum] = { false };

typedef struct QNode
{
	char data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct
{
	QueuePtr rear;
	QueuePtr front;
}LinkQueue;

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
	int weight;
} ArcNode;

typedef struct VNode
{
	char data;
	ArcNode* firstarc;
} VNode, AdjList[MVNum];

typedef struct
{
	AdjList vertices;
	int visited[MVNum];
	int vexnum, arcnum;
} ALGraph;

void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return;
}

void Enqueue(LinkQueue& Q, char ch)
{
	QueuePtr p;
	p = new QNode;
	p->data = ch;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

int DeQueue(LinkQueue& Q, char& e)
{
	if (Q.front == Q.rear)
		return 0;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear = Q.front;
	}
	delete p;
	return 1;
}

void OutputQueue(LinkQueue Q)
{
	QueuePtr p;
	{
		cout << p->data;
		p = Q.front->next;
		while (p != NULL)
			p = p->next;
	}
}

int EnQueue(LinkQueue& Q, char e)
{
	QueuePtr p = new QNode;
	p->data = e;
	Q.rear->next = p;
	Q.rear = p;
	p->next = NULL;
	return 1;
}

int QEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return 1;
	}
	return 0;
}

int LocateVex_ALGraph(ALGraph& G, char v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

int CreateUDG(ALGraph& G)
{
	int i, j, k;
	ArcNode* p1, * p2;
	char v1, v2;
	cout << "请输入顶点数边数:";
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << "请输入顶点:";
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "请输入需要连接的顶点:";
		cin >> v1 >> v2;
		i = LocateVex_ALGraph(G, v1);
		j = LocateVex_ALGraph(G, v2);

		p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return 1;
}

int* BFS(ALGraph G, char vexBegin, char vexEnd)
{
	char top;
	VNode* topNode;
	ArcNode* pt;
	LinkQueue queue;
	int w, i = 0;
	bool visited[MVNum] = { false };
	int* a = new int[MVNum];
	InitQueue(queue);
	EnQueue(queue, vexBegin);
	visited[LocateVex_ALGraph(G, vexBegin)] = true;
	int path[100];
	path[LocateVex_ALGraph(G, vexBegin)] = -1;
	while (!QEmpty(queue))
	{
		DeQueue(queue, top);
		topNode = &G.vertices[LocateVex_ALGraph(G, top)];
		pt = topNode->firstarc;
		while (pt)
		{
			if (!visited[pt->adjvex])
			{
				visited[pt->adjvex] = true;
				EnQueue(queue, G.vertices[pt->adjvex].data);
				path[pt->adjvex] = LocateVex_ALGraph(G, topNode->data);
			}
			if (G.vertices[pt->adjvex].data == vexEnd)
			{
				w = pt->adjvex;
				while (w != -1)
				{
					a[MVNum - 1 - i] = w;
					w = path[w];
					i++;
				}
				a[MVNum - 1 - i] = -1;
				return a;
			}
			pt = pt->nextarc;
		}
	}
}

void Output(ALGraph G)
{
	int i, j;
	char v_head, v_end;
	cout << "请输入顶点和终点: ";
	cin >> v_head >> v_end;
	int* b = BFS(G, v_head, v_end);
	cout << "邻接矩阵最短路径：";
	for (i = 0; b[i] != -1; i++);
	for (j = i + 1; j < MVNum; j++)
	{
		cout << G.vertices[b[j]].data << " ";
	}
	cout << endl;
}
/*
int main()
{
	ALGraph GL;
	CreateUDG(GL);
	Output(GL);
}

*/
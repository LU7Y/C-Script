#include <iostream>
#include <stack>
using namespace std;

#define N 100

typedef char ElemType;

/*
ͼ���ڽӾ�������
*/
typedef struct _MGraph
{
	int edges[N][N]; //�߼���
	int n; //������
}MGraph;

/*
�Ͽ�˹�����㷨
g�洢����ͼ�ı�
k��������Ķ���
path[i]�����i���������һ������
dis[i]�����k����������i����̾���
*/
void Dijkstra(MGraph& g, int k, int path[], int dis[])
{
	int* visited = new int[g.n](); //�洢�����Ƿ񱻷��ʹ�����ʼ��Ϊ0
	for (int i = 0; i < g.n; i++)
	{
		dis[i] = g.edges[k][i]; //��ʼ����̾�������
		path[i] = k; //��ʼ��·������
	}
	visited[k] = 1;
	dis[k] = 0;
	for (int cnt = 1; cnt < g.n; cnt++) //ѭ��n-1��
	{
		int imin = -1; //�洢��̱ߵ��±�
		for (int i = 0; i < g.n; i++) //Ѱ��û���ʹ�����̱�
		{
			if (!visited[i] && (imin == -1 || dis[i] < dis[imin]))
				imin = i;
		}
		visited[imin] = 1;
		for (int i = 0; i < g.n; i++) //����µĶ��㵽��������ľ�����̣�������̾����·��
		{
			if (!visited[i] && dis[imin] + g.edges[imin][i] < dis[i])
			{
				dis[i] = dis[imin] + g.edges[imin][i];
				path[i] = imin;
			}
		}
	}
	delete[] visited; //�ǵ��ͷ��ڴ�
}

/*
����ӿ�ʼ���㵽����k�����·��
*/
void DisplayPath(int k, int path[])
{
	stack<int> s;
	while (path[k] != k)
	{
		s.push(k);
		k = path[k];
	}
	s.push(k);
	int cnt = 0;
	while (!s.empty())
	{
		if (cnt++ > 0) cout << "->";
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

/*
���������㷨
g�洢����ͼ�ı�
dis[i][j]�洢����i������j����̾��볤��
path[i][j]�洢����j����һ������
*/
void Floyd(MGraph& g, int dis[][N], int path[][N])
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			dis[i][j] = (i == j ? 0 : g.edges[i][j]); //��ʼ����������
			path[i][j] = i; //��ʼ��·������
		}
	}
	for (int k = 0; k < g.n; k++)
	{
		for (int i = 0; i < g.n; i++)
		{
			for (int j = 0; j < g.n; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j]) //�����KΪ�м�������̣����¾��������·������
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

/*
���ÿ�Զ�������·��
*/
void DisplayPath(int n, int path[][N], int dis[][N])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << i << "-" << j << "���·�����ȣ�" << dis[i][j] << " ���·����";
			DisplayPath(j, path[i]);
		}
	}
}

int main()
{
	MGraph g;
	while (cin >> g.n)
	{
		for (int i = 0; i < g.n; i++)
			for (int j = 0; j < g.n; j++)
				g.edges[i][j] = INT16_MAX;
		int m, u, v, w;
		cin >> m;
		while (m-- > 0)
		{
			cin >> u >> v >> w;
			g.edges[u][v] = w;
		}
		//Dijkstra
		{
			int* path = new int[g.n];
			int* dis = new int[g.n];
			Dijkstra(g, 0, path, dis);
			for (int i = 0; i < g.n; i++)
			{
				cout << 0 << "-" << i << "���·�����ȣ�" << dis[i] << " ���·����";
				DisplayPath(i, path);
			}
			delete[] path, dis;
		}
		//Floyd
		{
			int path[N][N], dis[N][N];
			Floyd(g, dis, path);
			DisplayPath(g.n, path, dis);
		}
	}
	return 0;
}
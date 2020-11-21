#include <iostream>
#include <stack>
using namespace std;

#define N 100

typedef char ElemType;

/*
图的邻接矩阵声明
*/
typedef struct _MGraph
{
	int edges[N][N]; //边集合
	int n; //顶点数
}MGraph;

/*
迪克斯特拉算法
g存储有向图的边
k代表出发的顶点
path[i]保存第i个顶点的上一个顶点
dis[i]保存从k出发到顶点i的最短距离
*/
void Dijkstra(MGraph& g, int k, int path[], int dis[])
{
	int* visited = new int[g.n](); //存储顶点是否被访问过，初始化为0
	for (int i = 0; i < g.n; i++)
	{
		dis[i] = g.edges[k][i]; //初始化最短距离数组
		path[i] = k; //初始化路径数组
	}
	visited[k] = 1;
	dis[k] = 0;
	for (int cnt = 1; cnt < g.n; cnt++) //循环n-1次
	{
		int imin = -1; //存储最短边的下标
		for (int i = 0; i < g.n; i++) //寻找没访问过的最短边
		{
			if (!visited[i] && (imin == -1 || dis[i] < dis[imin]))
				imin = i;
		}
		visited[imin] = 1;
		for (int i = 0; i < g.n; i++) //如果新的顶点到其他顶点的距离更短，更新最短距离和路径
		{
			if (!visited[i] && dis[imin] + g.edges[imin][i] < dis[i])
			{
				dis[i] = dis[imin] + g.edges[imin][i];
				path[i] = imin;
			}
		}
	}
	delete[] visited; //记得释放内存
}

/*
输出从开始顶点到顶点k的最短路径
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
弗洛伊德算法
g存储有向图的边
dis[i][j]存储顶点i到顶点j的最短距离长度
path[i][j]存储顶点j的上一个顶点
*/
void Floyd(MGraph& g, int dis[][N], int path[][N])
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			dis[i][j] = (i == j ? 0 : g.edges[i][j]); //初始化距离数组
			path[i][j] = i; //初始化路径数组
		}
	}
	for (int k = 0; k < g.n; k++)
	{
		for (int i = 0; i < g.n; i++)
		{
			for (int j = 0; j < g.n; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j]) //如果以K为中间点距离更短，更新距离数组和路径数组
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

/*
输出每对顶点的最短路径
*/
void DisplayPath(int n, int path[][N], int dis[][N])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << i << "-" << j << "最短路径长度：" << dis[i][j] << " 最短路径：";
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
				cout << 0 << "-" << i << "最短路径长度：" << dis[i] << " 最短路径：";
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
#include <bits/stdc++.h>
using namespace std;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Graph
{
public:
	int V;
	int E;
	vector<vector<int>> adj;

	Graph(int _V, int _E)
	{
		this->V = _V;
		this->E = _E;
		this->adj = vector<vector<int>>(_V);
	}

	void addEdge(int u, int v)
	{
		adj[v ].push_back(u );
	}
};

vector<int> topoSort(Graph g)
{
	vector<int> indegree(g.V, 0);
	queue<int> Q;
	vector<int> topOrder;
	for (int i = 0; i < g.V; i++)
		for (int j = 0; j < g.adj[i].size();j++)
			indegree[g.adj[i][j]]++;

	// for (int i = 0; i < g.V; i++)
	// 	cout << indegree[i] << " ";
	for (int i = 0; i < g.V; i++)
		if (indegree[i] == 0)
			Q.push(i);

	while (Q.empty() == false)
	{
		int cur = Q.front();
		Q.pop();
		topOrder.push_back(cur);

		for (int i = 0; i < g.adj[cur].size(); i++)
		{
			indegree[g.adj[cur][i]]--;
			if (indegree[g.adj[cur][i]] == 0)
				Q.push(g.adj[cur][i]);
		}
	}
	reverse(topOrder.begin(), topOrder.end());
	return topOrder;
}

int main()
{
	FastIO;
	int n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (int i = 0; i < m; i++)
	{
		int ed1, ed2;
		cin >> ed1 >> ed2;
		g.addEdge(ed1, ed2);
	}
	vector<int> topo = topoSort(g);
	for (int i = 0; i < n; i++)
		cout << topo[i]<<" ";
	return 0;
}

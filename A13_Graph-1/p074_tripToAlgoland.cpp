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
	vector<string> paths;
	map<pair<int, int>, int> edges;
	Graph(int _V, int _E)
	{
		this->V = _V;
		this->E = _E;
		this->adj = vector<vector<int>>(_V);
		this->paths = vector<string>(_E);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}
};

vector<string> trip(Graph g, int start, int end)
{
	vector<int> dist(g.V, INT_MAX);
	queue<int> Q;
	vector<int> p(g.V, -1);
	dist[start] = 0;
	Q.push(start);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < g.adj[cur].size(); i++)
		{
			if (dist[g.adj[cur][i]] == INT_MAX)
			{
				Q.push(g.adj[cur][i]);
				dist[g.adj[cur][i]] = dist[cur] + 1;
				p[g.adj[cur][i]] = cur;
			}
		}
		if (cur == end)
			break;
	}
	vector<string> ans;
	if (p[end] != -1)
	{
		int temp = end;
		while (temp != start)
		{
			ans.push_back(g.paths[g.edges[make_pair(p[temp], temp)]]);
			temp = p[temp];
		}
		reverse(ans.begin(), ans.end());
	}
	else
		ans.push_back("Impossible");

	return ans;
}

int main()
{
	FastIO;
	int n, m;
	cin >> n >> m;
	Graph g(n, m);
	map<string, int> s;

	int k = 1;
	for (int i = 0; i < m; i++)
	{
		string u, v, l;
		cin >> u >> v >> l;
		if (!s[u])
			s[u] = k++;
		if (!s[v])
			s[v] = k++;
		g.addEdge(s[u] - 1, s[v] - 1);
		g.paths[i] = l;
		g.edges[make_pair(s[u] - 1, s[v] - 1)] = i;
	}
	string start, end;
	cin >> start >> end;
	int st = s[start], en = s[end];

	vector<string> ans = trip(g, st - 1, en - 1);

	if (ans[0] != "Impossible")
		cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}

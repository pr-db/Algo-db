#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Graph
{
public:
	ll V;
	ll E;
	vector<vector<ll>> adj;

	Graph(ll _V, ll _E)
	{
		this->V = _V;
		this->E = _E;
		this->adj = vector<vector<ll>>(_V);
	}

	void addEdge(ll u, ll v)
	{
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
};

vector<ll> BFS(Graph g)
{
	vector<ll> dist(g.V, INT_MAX);
	queue<ll> Q;
	vector<int> p(g.V, -1);

	dist[0] = 0;
	Q.push(0);
	while (Q.empty() == false)
	{
		ll cur = Q.front();
		Q.pop();

		for (ll i = 0; i < g.adj[cur].size(); i++)
		{
			if (dist[g.adj[cur][i]] == INT_MAX)
			{
				Q.push(g.adj[cur][i]);
				dist[g.adj[cur][i]] = dist[cur] + 1;
				p[g.adj[cur][i]] = cur;
			}
		}
		if (cur == g.V-1)
			break;
	}
	vector<ll> ans;
	if (p[g.V-1] != -1)
	{
		int temp = g.V-1;
		while (temp != 0)
		{
			ans.push_back(g.paths[g.edges[make_pair(p[temp], temp)]]);
			temp = p[temp];
		}
		reverse(ans.begin(), ans.end());
	}

	return ans;
}

int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (ll i = 0; i < m; i++)
	{
		ll ed1, ed2;
		cin >> ed1 >> ed2;
		g.addEdge(ed1, ed2);
	}
	ll src;
	cin >> src;
	vector<ll> shortest = BFS(g, src - 1);
	for (ll i = 0; i < shortest.size(); i++)
		cout << shortest[i] << " ";
	return 0;
}

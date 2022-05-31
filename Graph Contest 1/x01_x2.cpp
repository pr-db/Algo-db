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

void DFS(Graph g, vector<ll> vis)
ll vis(Graph g)
{
	ll ans = 0;
	vector<ll> vis(g.V);
	ll v = 0;
	while(v<g.V)
	{
		for (ll i = 0; i < g.V; i++)
		{
			
			for (ll j = 0; j < g.adj[i].size(); j++)
				if(vis[g.adj[i][j]]==0)
				{

				}
		}
	}
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
	ll src = 0;
	ll ans = 0;
	return 0;
}

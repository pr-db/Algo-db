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
		adj[u].push_back(v);
	}
};
vector<ll> top(Graph g)
{
	queue<ll> Q;
	vector<ll> in(g.V);
	vector<ll> t;

	for (ll i = 0; i < g.V; i++)
		for (auto u : g.adj[i])
			in[u]++;
	for (ll i = 0; i < g.V; i++)
		if (!in[i])
			Q.push(i);

	while (Q.size())
	{
		ll cur = Q.front();
		Q.pop();
		t.push_back(cur);
		for (auto u : g.adj[cur])
		{
			in[u]--;
			if (!in[u])
				Q.push(u);
		}
	}
	// cout << ans;
	return t;
}

vector<ll> bfs(Graph g)
{
	queue<ll> q;
	vector<ll> vis(g.V);
	vis[0] = 1;
	q.push(0);
	while (q.size())
	{
		ll cur = q.front();
		q.pop();
		for (auto u : g.adj[cur])
			if (!vis[u])
			{
				q.push(u);
				vis[u] = 1;
			}
	}
	return vis;
}
int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		g.addEdge(u - 1, v - 1);
	}

	vector<ll> vis = bfs(g);
	vector<ll> t = top(g);
	vector<ll> dist(g.V);

	for (auto v : t)
		if (vis[v])
			for (auto u : g.adj[v])
				dist[u] = max(dist[u], dist[v] + 1);

	if (dist[n - 1])
		cout << dist[n - 1] + 1;
	else
		cout << -1;
	return 0;
}

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
		adj[v].push_back(u);
	}
};

vector<ll> BFS(Graph g)
{
	vector<ll> d0(g.V, INT_MAX);
	vector<ll> dn(g.V, INT_MAX);

	queue<ll> Q;
	d0[0] = 0;
	Q.push(0);
	while (!Q.empty())
	{
		ll cur = Q.front();
		Q.pop();

		for (auto u : g.adj[cur])
			if (d0[u] == INT_MAX)
			{
				Q.push(u);
				d0[u] = d0[cur] + 1;
			}
	}

	dn[g.V - 1] = 0;
	Q.push(g.V - 1);
	while (!Q.empty())
	{
		ll cur = Q.front();
		Q.pop();

		for (auto u : g.adj[cur])
			if (dn[u] == INT_MAX)
			{
				Q.push(u);
				dn[u] = dn[cur] + 1;
			}
	}
	vector<ll> ans;
	// cout << dn[0] << " ";
	for (ll i = 0; i < g.V; i++)
		if ((dn[0] != INT_MAX) && (d0[i] + dn[i] == dn[0]))
			ans.push_back(i);

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
		ll u, v;
		cin >> u >> v;
		g.addEdge(u - 1, v - 1);
	}
	vector<ll> ans = BFS(g);
	if (ans.size())
		for (ll i = 0; i < ans.size(); i++)
			cout << ans[i] + 1 << " ";
	else
		cout << -1;
	return 0;
}

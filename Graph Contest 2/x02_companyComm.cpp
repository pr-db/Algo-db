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
	ll n;
	ll m;
	vector<vector<ll>> adj;
	vector<bool> vis;
	vector<vector<ll>> lang;

	Graph(ll _n, ll _m)
	{
		this->n = _n;
		this->m = _m;
		this->adj = vector<vector<ll>>(_n);
		this->vis = vector<bool>(_n);
		this->lang = vector<vector<ll>>(_m);
	}

	void addEdge(ll u, ll v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};

void BFS(Graph &g, ll src)
{
	queue<ll> Q;
	Q.push(src);
	g.vis[src] = 1;

	while (Q.size())
	{
		ll cur = Q.front();
		Q.pop();

		for (ll u : g.adj[cur])
			if (!g.vis[u])
			{
				Q.push(u);
				g.vis[u] = 1;
			}
	}
}

int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);

	for (ll i = 0; i < n; i++)
	{
		ll s, t;
		cin >> s;
		for (ll j = 0; j < s; j++)
		{
			cin >> t;
			g.lang[t - 1].push_back(i);
		}
	}
	for (ll i = 0; i < m; i++)
		if (g.lang[i].size() > 1)
			for (ll j = 1; j < g.lang[i].size(); j++)
				g.addEdge(g.lang[i][0], g.lang[i][j]);

	ll ans = 0;
	for (ll i = 0; i < n; i++)
		if (!g.vis[i])
		{
			ans++;
			BFS(g, i);
		}

	if (ans == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}

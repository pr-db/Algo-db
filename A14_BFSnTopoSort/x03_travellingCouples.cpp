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

	Graph(ll _n, ll _m)
	{
		this->n = _n;
		this->m = _m;
		this->adj = vector<vector<ll>>(_n);
	}

	void edge(ll u, ll v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};

vector<ll> BFS(Graph g, ll src)
{
	vector<ll> dist(g.n, INT_MAX);
	queue<ll> Q;

	dist[src] = 0;
	Q.push(src);
	while (!Q.empty())
	{
		ll cur = Q.front();
		Q.pop();

		for (auto u : g.adj[cur])
		{
			if (dist[u] == INT_MAX)
			{
				Q.push(u);
				dist[u] = dist[cur] + 1;
			}
		}
	}
	return dist;
}

int main()
{
	FastIO;
	ll c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (ll i = 0; i < m; i++)
	{
		ll ed1, ed2;
		cin >> ed1 >> ed2;
		g.edge(ed1 - 1, ed2 - 1);
	}

	vector<ll> male = BFS(g, 0);
	vector<ll> female = BFS(g, 1);
	vector<ll> dest = BFS(g, n - 1);
	ll ans = INT_MAX;
	for (ll i = 0; i < n; i++)
		ans = min(c1 * male[i] + c2 * female[i] + c3 * dest[i], ans);
	cout << ans;
	return 0;
}

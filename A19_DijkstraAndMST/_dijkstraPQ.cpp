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
	vector<vector<pair<ll, ll>>> adj;

	Graph(ll _n, ll _m)
	{
		this->n = _n;
		this->m = _m;
		this->adj = vector<vector<pair<ll, ll>>>(_n);
	}

	void addEdge(ll u, ll v, ll wt)
	{
		adj[u - 1].push_back(make_pair(v - 1, wt));
	}
};

void dijkstra(Graph &g, ll s, vector<ll> &d, vector<ll> &p)
{
	ll n = g.adj.size();
	d.assign(n, INT_MAX);
	p.assign(n, -1);

	d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty())
	{
		ll v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : g.adj[v])
		{
			ll to = edge.first;
			ll len = edge.second;

			if (d[v] + len < d[to])
			{
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
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
		ll u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	vector<ll> d, p;
	dijkstra(g, 0, d, p);
	for(auto u : d)
		cout << u << " ";
	cout << "\n";
	for (auto u : p)
		cout << u << " ";

	return 0;
}

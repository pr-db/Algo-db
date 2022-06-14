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
	vector<vector<pair<ll, ll>>> radj;

	Graph(ll _n, ll _m)
	{
		this->n = _n;
		this->m = _m;
		this->adj = vector<vector<pair<ll, ll>>>(_n);
		this->radj = vector<vector<pair<ll, ll>>>(_n);
	}

	void addEdge(ll u, ll v, ll wt)
	{
		adj[u - 1].push_back(make_pair(v - 1, wt));
		radj[v - 1].push_back(make_pair(u - 1, wt));
	}
};

void dijkstra(vector<vector<pair<ll, ll>>> adj, ll s, vector<ll> &d)
{
	ll n = adj.size();
	d.assign(n, INT64_MAX);

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

		for (auto edge : adj[v])
		{
			ll to = edge.first;
			ll len = edge.second;

			if (d[v] + len < d[to])
			{
				d[to] = d[v] + len;
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
	vector<ll> d1, dn;
	dijkstra(g.adj, 0, d1);
	dijkstra(g.radj, n - 1, dn);

	ll ans = INT64_MAX;

	// for (ll i = 0; i < n; i++)
	// 	cout << d1[i] << " ";
	// cout << "\n";
	// for (ll i = 0; i < n; i++)
	// 	cout << dn[i] << " ";
	// cout << "\n";

	for (ll i = 0; i < n; i++)
		for (auto u : g.adj[i])
		{
			if (d1[i] == INT64_MAX || dn[u.first] == INT64_MAX)
				continue;
			ans = min(ans, d1[i] + dn[u.first] + u.second / 2);
		}
	cout << ans;
	return 0;
}

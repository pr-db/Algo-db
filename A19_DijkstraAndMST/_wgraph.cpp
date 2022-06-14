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

	return 0;
}

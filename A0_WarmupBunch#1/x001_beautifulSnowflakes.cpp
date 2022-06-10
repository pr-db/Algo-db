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
		g.edge(ed1 - 1, ed2 - 1);
	}
	map<ll, ll> ans;
	// cout << g.adj[2].size()<<" \n";
	for (ll i = 0; i < n; i++)
	{
		if (g.adj[i].size() > 1)
		{
			ll ct = 1;
			for (auto u : g.adj[i])
			{
				if (g.adj[u].size() > 1)
				{
					ct = 0;
					break;
				}
				// cout << u << " ";
			}
			// cout << g.adj[i] << " ";
			if (ct)
				ans[g.adj[i].size()]++;
		}
		else if (g.adj[i].size()==0)
			ans[0]++;
	}
	ll ct = 0;
	for (auto u : ans)
		if (u.second == 1)
			ct++;
	cout << ct;
	return 0;
}

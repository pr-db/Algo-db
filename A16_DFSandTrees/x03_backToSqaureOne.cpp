#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> vis;
bool loop = false;
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
		adj = vector<vector<ll>>(_n);
	}
	void edge(ll u, ll v)
	{
		adj[u].push_back(v);
	}
};
void DFS(Graph &g, ll cur)
{
	if (loop)
		return;
	vis[cur]++;
	for (auto child : g.adj[cur])

		if (vis[child] == 1)
		{
			loop = true;
			return;
		}
		else if (!vis[child])
			DFS(g, child);
	vis[cur]++;
}
int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	vis = vector<ll>(n);
	for (ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		g.edge(u, v);
	}

	// for (ll i = 0; i < n; i++)
	// {
	// 	for (auto u : g.adj[i])
	// 		cout << u << " ";
	// 	cout << "\n";
	// }
	for (ll i = 0; i < n; i++)
		if (!vis[i])
			DFS(g, i);
	if (loop)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}

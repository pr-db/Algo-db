#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<vector<int>> adj;
vector<bool> vis;
void BFS(ll src)
{
	queue<ll> Q;
	Q.push(src);
	vis[src] = 1;

	while (Q.size())
	{
		ll cur = Q.front();
		Q.pop();

		for (ll u : adj[cur])
			if (!vis[u])
			{
				Q.push(u);
				vis[u] = 1;
			}
	}
}

int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);

	for (ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++)
		if (!vis[i])
		{
			ans++;
			BFS(i);
		}
	cout << ans - 1;
	return 0;
}

// diameter of tree
// ye hota h maximum distance between any two nodes

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void dfs(ll node, vector<ll> adj[], vector<bool> &vis, ll cnt, vector<ll> &dis)
{
	dis[node] = cnt;
	vis[node] = true;

	for (auto x : adj[node])
	{
		if (!vis[x])
		{
			dfs(x, adj, vis, cnt + 1, dis);
		}
	}
}

int main()
{

	ll n;
	cin >> n;

	vector<ll> adj[n + 1];
	ll u, v;
	for (ll i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> dis(n + 1, 0);
	vector<bool> vis(n + 1, false);
	dfs(1, adj, vis, 0, dis);

	ll mx = 0;
	ll mxi = 0;
	for (ll i = 1; i <= n; i++)
	{
		mx = max(mx, dis[i]);
		// cout << mx << " ";
		if (dis[i] == mx)
		{
			mxi = i;
		}
		cout << mxi << " ";
		dis[i] = 0;
		vis[i] = false;
	}

	dfs(mxi, adj, vis, 0, dis);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		ans = max(ans, dis[i]);
	}
	cout << ans << "\n";

	return 0;
}
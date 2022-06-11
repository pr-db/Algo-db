#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool solve(ll node, vector<bool> &vis, vector<bool> &dvis, vector<ll> adj[])
{
	vis[node] = true;
	dvis[node] = true;

	for (auto x : adj[node])
	{
		if (vis[x] && dvis[x])
		{
			cout << x << "\n";
			return true;
		}
		if (!vis[x])
		{
			if (solve(x, vis, dvis, adj))
			{
				return true;
			}
		}
	}
	dvis[node] = false;
	return false;
}

int main()
{

	ll n, m;
	cin >> n >> m;

	vector<ll> adj[n + 1];

	for (ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> vis(n + 1, false);
	vector<bool> dvis(n + 1, false);

	bool flag = false;
	for (ll i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (solve(i, vis, dvis, adj))
			{
				flag = true;
				break;
			}
		}
	}

	if (flag)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> tpo(ll n, ll m, vector<ll> adj[])
{

	vector<ll> ans;
	vector<ll> indegree(n + 1, 0);

	for (ll i = 0; i < n; i++)
	{
		for (auto x : adj[i])
		{
			indegree[x] += 1;
		}
	}

	queue<ll> q;

	for (ll i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		ll curr = q.front();
		q.pop();
		ans.push_back(curr);

		for (auto x : adj[curr])
		{
			indegree[x] -= 1;
			if (indegree[x] == 0)
			{
				q.push(x);
			}
		}
	}

	return ans;
}

int main()
{
	// n vertices h m edges h
	ll n, m;
	cin >> n >> m;

	vector<ll> adj[n + 1];
	for (ll i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;

		// u se v tak jaata h
		adj[u].push_back(v);
	}

	vector<ll> dis(n + 1, 0);

	dis[1] = 0;

	vector<ll> ans = tpo(n, m, adj);

	for (ll i = 0; i < ans.size(); i++)
	{
		for (auto x : adj[i])
		{
			dis[x] = max(dis[x], dis[i] + 1);
		}
	}
	if (dis[n])
	{
		cout << dis[n] + 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}

	return 0;
}
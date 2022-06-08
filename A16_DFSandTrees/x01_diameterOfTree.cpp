#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
vector<ll> dist;
void DFS(vector<vector<ll>> &adj, ll cur, ll par = -1)
{
	if (par != -1)
		dist[cur] = dist[par] + 1;
	else
		dist[cur] = 0;
	for (auto child : adj[cur])
		if (child != par)
			DFS(adj, child, cur);
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	dist = vector<ll>(n);
	vector<vector<ll>> adj(n);
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	DFS(adj, 0);
	ll m = INT_MIN;
	ll mi = -1;
	for (ll i = 0; i < n; i++)
	{
		if(dist[i]>m)
		{
			m = dist[i];
			mi = i;
		}
	}

	DFS(adj, mi);
	m = INT_MIN;
	for (ll i = 0; i < n; i++)
		if (dist[i] > m)
			m = dist[i];
	cout << m;
	return 0;
}

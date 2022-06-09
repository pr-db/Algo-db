#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> parent;
void DFS(vector<ll> &dist, vector<vector<ll>> &adj, ll cur, ll par = -1)
{
	parent[cur] = par;
	if (par != -1)
		dist[cur] = dist[par] + 1;	
	else
		dist[cur] = 0;
	for (auto child : adj[cur])
		if (child != par)
			DFS(dist, adj, child, cur);
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> dist1(n);
	vector<ll> dist2(n);
	vector<ll> dist3(n);

	parent = vector<ll>(n);

	vector<vector<ll>> adj(n);
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	DFS(dist1, adj, 0);
	ll m = INT_MIN;
	ll i1 = -1;
	ll i2 = -1;

	// for (ll i = 0; i < n; i++)
	// 	cout << dist1[i] << " ";
	// cout << "\n";
	for (ll i = 0; i < n; i++)
	{
		if (dist1[i] > m)
		{
			m = dist1[i];
			i1 = i;
		}
	}

	// cout << i1 << "\n";
	DFS(dist2, adj, i1);
	m = INT_MIN;
	for (ll i = 0; i < n; i++)
		if (dist2[i] > m)
		{
			m = dist2[i];
			i2 = i;
		}

	// cout << i1 << " " << i2 << "\n";
	DFS(dist3, adj, i2);

	for (ll i = 0; i < n; i++)
	{
		cout << max(dist3[i], dist2[i]) << " ";
	}

	return 0;
}

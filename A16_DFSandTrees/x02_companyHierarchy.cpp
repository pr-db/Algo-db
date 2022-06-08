#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
vector<ll> hier;
ll DFS(vector<vector<ll>> &adj, ll cur, ll par = -1)
{	
	ll sum = 0;
	for (auto child : adj[cur])
		if (child != par)
			sum+=DFS(adj, child, cur)+1;
	return hier[cur] = sum;
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	hier = vector<ll>(n);
	vector<vector<ll>> adj(n);
	for (ll i = 1; i < n; i++)
	{
		ll u;
		cin >> u ;
		adj[u - 1].push_back(i);
		adj[i].push_back(u - 1);
	}

	DFS(adj, 0);
	for (ll i = 0; i < n; i++)
	cout << hier[i]<<" ";
	return 0;
}

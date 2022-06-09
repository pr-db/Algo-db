#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Tree
{
public:
	ll n;
	vector<vector<ll>> adj;
	vector<ll> hier;
	vector<ll> cost;
	vector<ll> profit;

	Tree(ll _n)
	{
		this->n = _n;
		hier = vector<ll>(_n);
		adj = vector<vector<ll>>(_n);
		cost = vector<ll>(_n);
		profit = vector<ll>(_n);
	}
	void edge(ll u, ll v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};
ll DFS(Tree &t, ll cur, ll par = -1)
{
	ll profit = t.cost[cur];
	for (auto child : t.adj[cur])
		if (child != par)
		{
			profit += DFS(t, child, cur);
		}
	return t.profit[cur] = profit;
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	Tree t(n);
	for (ll i = 1; i < n; i++)
	{
		ll u;
		cin >> u;
		t.edge(u - 1, i);
	}
	for (ll i = 0; i < n; i++)
		cin >> t.cost[i];
	
	DFS(t, 0);
	ll ans = INT_MIN;
	for (ll i = 0; i < n; i++)
		ans = max(ans, t.profit[i]);

	// for (ll i = 0; i < n; i++)
	// 	cout << t.profit[i] << " ";
	cout << ans;

	return 0;
}

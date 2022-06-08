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
	ll c;
	vector<vector<ll>> adj;
	vector<ll> color;
	Tree(ll _n, ll _c)
	{
		this->n = _n;
		this->c = _c;
		color = vector<ll>(_n);
		adj = vector<vector<ll>>(_n);
	}
	void edge(ll u, ll v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};
ll DFS(Tree t, ll cr, ll cur, ll par = -1)
{
	if (t.color[cur])
		cr++;
	else
		cr = 0;

	if (cr > t.c)
		return 0;

	ll sum = 0;
	for (auto child : t.adj[cur])
		if (child != par)
			sum += DFS(t, cr, child, cur);
	if (t.adj[cur].size() <= 1)
		sum++;
	return sum;
}
int main()
{
	FastIO;
	ll n, c;
	cin >> n >> c;
	Tree t(n, c);
	for (ll i = 0; i < n; i++)
		cin >> t.color[i];

	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		t.edge(u - 1, v - 1);
	}
	cout << DFS(t, 0, 0);
	return 0;
}

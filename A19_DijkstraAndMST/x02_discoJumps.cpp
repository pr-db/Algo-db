#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
enum
{
	T,
	R,
	B,
	L
};
class Edge
{
public:
	long long u, v, w;
	bool operator<(Edge const &other)
	{ // helps find edge with smaller wegiht b/w two variable of Edge type
		return w < other.w;
	}
};

class DSU
{
public:
	vector<ll> par;
	DSU(ll nComponents)
	{
		par.resize(nComponents, -1);
	}
	ll root(ll v)
	{
		if (par[v] < 0)
			return v;
		return par[v] = root(par[v]);
	} // finds component number of an entity

	void merge(ll x, ll y)
	{ // merges two different components into one
		if ((x = root(x)) == (y = root(y)))
			return;
		if (par[y] < par[x])
			swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}
};

void kruskal(ll n, vector<Edge> edges)
{
	long long ans = 0;
	DSU dsu(n + 1);

	sort(edges.begin(), edges.end());
	for (ll i = 0; i < edges.size(); ++i)
	{
		if (dsu.root(edges[i].u) != dsu.root(edges[i].v))
		{ // edge connects two nodes of different components
			dsu.merge(edges[i].u, edges[i].v);
			ans += edges[i].w;
		}
		cout << dsu.par[i] << " ";
	}

	unordered_set<ll> countComponents;
	for (ll i = 1; i <= n; ++i)
		countComponents.insert(dsu.root(i));
	if (countComponents.size() > 1)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << "\n";
}

int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	vector<Edge> edges;
	vector<vector<ll>> disks;
	for (ll i = 0; i < m * n; i++)
	{
		vector<ll> disk(4);
	}
	kruskal(n, edges);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

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
	vector<int> par;
	DSU(int nComponents)
	{
		par.resize(nComponents, -1);
	}
	int root(int v)
	{
		if (par[v] < 0)
			return v;
		return par[v] = root(par[v]);
	} // finds component number of an entity

	void merge(int x, int y)
	{ // merges two different components into one
		if ((x = root(x)) == (y = root(y)))
			return;
		if (par[y] < par[x])
			swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}
};

void kruskal(int n, vector<Edge> edges)
{
	long long ans = 0;
	DSU dsu(n + 1);

	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); ++i)
	{
		if (dsu.root(edges[i].u) != dsu.root(edges[i].v))
		{ // edge connects two nodes of different components
			dsu.merge(edges[i].u, edges[i].v);
			ans += edges[i].w;
		}
		cout << dsu.par[i] << " ";
	}

	unordered_set<int> countComponents;
	for (int i = 1; i <= n; ++i)
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
	vector<Edge> edges(m);
	for (ll i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	kruskal(n, edges);

	return 0;
}

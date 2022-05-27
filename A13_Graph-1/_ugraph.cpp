#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Graph
{
private:
	vector<ll> path;

public:
	ll V;
	ll E;
	vector<ll> *adj;
	vector<vector<ll>> paths;

	Graph(ll _V, ll _E)
	{
		this->V = _V;
		this->E = _E;
		this->adj = new vector<ll>[_V];
	}
	void addEdge(ll u, ll v)
	{
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
};


int main()
{
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (ll i = 0; i < m; i++)
	{
		ll ed1, ed2;
		cin >> ed1 >> ed2;
		g.addEdge(ed1, ed2);
	}
	return 0;
}

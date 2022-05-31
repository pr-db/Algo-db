#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Graph
{
public:
	ll V;
	ll E;
	vector<vector<ll>> adj;

	Graph(ll _V, ll _E)
	{
		this->V = _V;
		this->E = _E;
		this->adj = vector<vector<ll>>(_V);
	}

	void addEdge(ll u, ll v)
	{
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
};

ll BFS(Graph g, ll src)
{
	vector<ll> dist(g.V, INT_MAX);
	queue<ll> Q;
	vector<ll> vis;
	vector<ll> v(g.V, 1);
	ll ans=0;
	while (vis.size() != g.V)
	{
		dist[src] = 0;
		Q.push(src);
		v[src] = 1;
		vis.push_back(src);
		while (Q.empty() == false)
		{
			ll cur = Q.front();
			Q.pop();

			for (ll i = 0; i < g.adj[cur].size(); i++)
			{
				if (dist[g.adj[cur][i]] == INT_MAX)
				{
					Q.push(g.adj[cur][i]);
					dist[g.adj[cur][i]] = dist[cur] + 1;
					vis.push_back(g.adj[cur][i]);
					
				}
			}
		}
		for (ll i = 0; i < g.V; i++)
			if (v[i] != 1)
			{
				src = i;
				ans++;
				// cout << src << " ";

				break;
			}
			// cout << v[i] << " ";
		}
		return ans;
}

int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;
	Graph g(n, m);
	for (ll i = 0; i < m; i++)
	{
		ll ed1, ed2;
		cin >> ed1 >> ed2;
		g.addEdge(ed1, ed2);
	}
	ll src = 0;
	// ll ans = 0;
	ll ans = BFS(g, 0);
	
	cout << ans;
	return 0;
}

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

vector<ll> BFS(Graph g, ll src)
{
	vector<ll> dist(g.V, INT_MAX);
	queue<ll> Q;

	dist[src] = 0;
	Q.push(src);
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
			}
		}
	}
	return dist;
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
	ll ans = 0;
	vector<ll> s = BFS(g, 0);
	map<ll, ll> done;
	while (1)
	{
		ll ind = -1;
		// for (ll i = 0; i < g.V; i++)
		// 	cout << s[i] << " ";
		// cout << "\n";
		for (ll i = 0; i < g.V; i++)
			if (s[i] != INT_MAX && s[i] != -1)
			{
				s[i] = -1;
				done[i]++;
			}
			else if (s[i] == INT_MAX && done[i] == 0)
				ind = i;
		// cout << ind << " ";
		if (ind == -1)
			break;
		s = BFS(g, ind);
		ans++;
	}
	cout << ans;
	return 0;
}

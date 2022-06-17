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
class Graph
{
public:
	ll n;
	vector<vector<pair<ll, ll>>> adj;
	vector<vector<char>> disks;

	Graph(ll _n)
	{
		this->n = _n;
		this->adj = vector<vector<pair<ll, ll>>>(_n);
	}

	void addEdge(ll u, ll v, ll wt)
	{
		adj[u].push_back(make_pair(v, wt));
	}
};

void dijkstra(Graph &g, ll s, vector<ll> &d)
{
	ll n = g.adj.size();
	d.assign(n, INT_MAX);

	d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty())
	{
		ll v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : g.adj[v])
		{
			ll to = edge.first;
			ll len = edge.second;

			if (d[v] + len < d[to])
			{
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}
}

int main()
{
	FastIO;

	ll n, m;
	cin >> n >> m;
	Graph g(n * m);

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			vector<char> disk(4);
			cin >> disk[T] >> disk[R] >> disk[B] >> disk[L];
			g.disks.push_back(disk);
		}
	}
	ll s = g.disks.size();

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			ll ind = i * m + j;
			ll k = 0;
			if (i > 0)
			{
				k = 0;
				while (g.disks[ind][k] != g.disks[ind - m][B])
					k++;
				if (T - k >= 0)
					g.addEdge(ind, ind - m, T - k);
				else
					g.addEdge(ind, ind - m, T - k + 4);
			}
			if (j < m - 1)
			{
				k = 0;
				while (g.disks[ind][k] != g.disks[ind + 1][L])
					k++;

				if (R - k >= 0)
					g.addEdge(ind, ind + 1, R - k);
				else
					g.addEdge(ind, ind + 1, R - k + 4);
			}
			if (j > 0)
			{
				k = 0;
				while (g.disks[ind][k] != g.disks[ind - 1][R])
					k++;
				if (L - k >= 0)
					g.addEdge(ind, ind - 1, L - k);
				else
					g.addEdge(ind, ind - 1, L - k + 4);
			}
			if (i < n - 1)
			{
				k = 0;
				while (g.disks[ind][k] != g.disks[ind + m][T])
					k++;
				if (B - k >= 0)
					g.addEdge(ind, ind + m, B - k);
				else
					g.addEdge(ind, ind + m, B - k + 4);
			}
		}
	}

	vector<ll> d;
	dijkstra(g, 0, d);
	cout << d[m*n - 1];

	return 0;
}

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
	ll n;
	vector<vector<ll>> circle;
	vector<vector<ll>> adj;

	Graph(ll _n)
	{
		this->n = _n;
		this->adj = vector<vector<ll>>(_n + 4);
		this->circle = vector<vector<ll>>(_n, vector<ll>(3));
	}

	void edge(ll u, ll v)
	{
		adj[u + 4].push_back(v + 4);
		adj[v + 4].push_back(u + 4);
	}
	void draw(ll i, ll x, ll y, ll r)
	{
		circle[i][0] = x;
		circle[i][1] = y;
		circle[i][2] = r;
	}
};

vector<ll> BFS(Graph g, ll src)
{
	vector<ll> vis(g.n + 4);
	queue<ll> Q;

	vis[src]++;
	Q.push(src);
	while (!Q.empty())
	{
		ll cur = Q.front();
		Q.pop();

		for (auto u : g.adj[cur])
		{
			if (!vis[u])
			{
				Q.push(u);
				vis[u]++;
			}
		}
	}
	return vis;
}

int main()
{
	FastIO;
	ll t;
	cin >> t;
	while (t--)
	{
		ll x, y;
		cin >> x >> y;

		ll n;
		cin >> n;
		Graph g(n);
		for (ll i = 0; i < n; i++)
		{
			ll x, y, r;
			cin >> x >> y >> r;
			g.draw(i, x, y, r);
		}
		ll i = 0, j = 0;

		for (ll i = 0; i < n; i++)
		{
			for (ll j = i + 1; j < n; j++)
				if ((abs(pow(g.circle[i][0] - g.circle[j][0], 2) + pow(g.circle[i][1] - g.circle[j][1], 2))) <= pow((g.circle[i][2] + g.circle[j][2]), 2))
					g.edge(i, j);
			if (g.circle[i][0] - g.circle[i][2] <= 0)
			{
				// cout << "L";
				g.edge(i, -4);
			}
			if (g.circle[i][0] + g.circle[i][2] >= x)
			{
				// cout << "R";
				g.edge(i, -3);
			}
			if (g.circle[i][1] - g.circle[i][2] <= 0)
			{
				// cout << "D";
				g.edge(i, -2);
			}
			if (g.circle[i][1] + g.circle[i][2] >= y)
			{
				// cout << "U";
				g.edge(i, -1);
			}
		}
		// for (ll i = 0; i < n + 4; i++)
		// {
		// 	cout << i << ": ";
		// 	for (auto u : g.adj[i])
		// 		cout << u << " ";
		// 	cout << "\n";
		// }
		vector<ll> visL = BFS(g, 0);
		vector<ll> visR = BFS(g, 1);
		vector<ll> visD = BFS(g, 2);
		vector<ll> visU = BFS(g, 3);

		// for (ll i = 0; i < n + 4; i++)
		// 	cout << visL[i] << " ";
		// cout << "\n";
		// for (ll i = 0; i < n + 4; i++)
		// 	cout << visR[i] << " ";
		// cout << "\n";
		// for (ll i = 0; i < n + 4; i++)
		// 	cout << visD[i] << " ";
		// cout << "\n";
		// for (ll i = 0; i < n + 4; i++)
		// 	cout << visU[i] << " ";
		// cout << "\n";

		bool ans = not(visL[1] or visL[3] or visR[2] or visR[0] or visD[3] or visD[1] or visU[2] or visU[0]);

		if (ans)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}

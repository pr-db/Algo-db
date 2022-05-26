#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
int main()
{
	FastIO;
	ll n, m;
	cin >> n >> m;

	map<string, ll> s;
	vector<vector<ll>> a(n);
	vector<vector<string>> adj(n, vector<string>(n));
	vector<vector<ll>> vis(n, vector<ll>(n));

	ll k = 1;
	for (ll i = 0; i < n; i++)
	{
		string u, v, l;
		cin >> u >> v >> l;
		if (!s[u])
			s[u] = k++;
		if (!s[v])
			s[v] = k++;
		adj[s[u] - 1][s[v] - 1] = l;
		vis[s[u] - 1][s[v] - 1] = 1;
	}
	string start, end;
	ll st = s[start], en = s[end];
	cin >> start >> end;
	vector<string> ans;
	for (ll i = 0; i < n;)
	{	
		for (ll j = 0; j < n;)
		{
			if()
			if (vis[i][j] == 1)
			{
				i = j;
				break;
			}
			else
				j++;
		}

		}
	return 0;
}

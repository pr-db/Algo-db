
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, q;
	cin >> n >> m >> q;
	ll a[n][m];
	map<ll, pair<ll, ll>> mp;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
		{
			cin >> a[i][j];
			mp[a[i][j]] = {i, j};
		}

	ll b[q];
	for (ll p = 0; p < q; p++)
	{
		cin >> b[p];
		cout << mp[b[p]].first << " " << mp[b[p]].second << "\n";
	}
	return 0;
}

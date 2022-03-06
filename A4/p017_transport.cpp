#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, c;
	cin >> n >> m >> c;
	vector<ll> a(n);
	vector<vector<ll>> b;

	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0, f = 0;
	for (ll i = 0; i < m && f < n; i++)
	{
		vector<ll> temp;
		for (ll j = 0; j < c && f < n; j++, f++)
			temp.push_back(a[i * c + j]);
		b.push_back(temp);
	}
	f = 0;
	for (ll i = 0; i < b.size(); i++)
	{
		for (ll j = 0; j < b[i].size(); j++)
			cout << b[i][j] << " ";
		cout << "\n";
	}
	cout << ans;
	return 0;
}

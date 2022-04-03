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
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector<ll> mp(m, -1);
	for (ll i = 0; i < n; i++)
	{
		ll c = 1;
		for (ll k = 0; k < m; k++)
			if (mp[k] == a[i])
			{
				c = 0;
				break;
			}
		if (c)
			if (mp[a[i] % m] == -1)
			{
				mp[a[i] % m] = a[i];
				// cout << a[i] % m<<"  ";
			}
			else
			{
				ll j = 1;
				while (j < m && mp[(a[i] + j) % m] != -1)
					j++;
				if (j < m)
					mp[(a[i] + j) % m] = a[i];
				else
					break;
			}
		else
			continue;
	}
	for (ll i = 0; i < m; i++)
		cout << mp[i] << " ";
	return 0;
}

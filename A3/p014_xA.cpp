#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

// 1 1 2 2 3 6 100 101
//  0   0   3     1
//    1   1   94

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x, inp;
	cin >> x;
	ll n = 2 * x;
	vector<ll> v;
	for (ll i = 0; i < n; i++)
	{
		cin >> inp;
		v.push_back(inp);
	}
	sort(v.begin(), v.end());

	ll ans = 10000000;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			vector<ll> c;
			for (ll k = 0; k < n; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}
				c.push_back(v[k]);
			}

			ll sum = 0;
			for (ll i = 0; i < c.size(); i++)
			{
				if (i % 2 != 0)
				{
					sum += (c[i] - c[i - 1]);
				}
			}
			ans = min(ans, sum);
		}
	}

	cout << ans << "\n";

	return 0;
}
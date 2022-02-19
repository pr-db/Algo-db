#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll c[n], sum[n];
	cin >> c[0];
	sum[0] = c[0];

	for (ll i = 1; i < n; i++)
	{
		cin >> c[i];
		sum[i] = sum[i - 1] + c[i];
	}
	ll k;
	cin >> k;
	ll a[k][2];
	for (ll i = 0; i < k; i++)
		cin >> a[i][0] >> a[i][1];
	ll curr = 0;
	ll next = 0;
	for (ll i = 0; i < k; i++)
	{
		if (a[i][0] > 0)
		{
			next += a[i][1] % n;
			next %= n;
		}
		else
		{
			next -= a[i][1] % n;
			next += n;
			next %= n;
		}
		ll c1 = 0, c2 = 0;
		ll i1 = min(curr, next), i2 = max(curr, next);
		c1= sum[i2]-sum[i1];
		c2 = sum[n - 1] - c1;
		ll cost = min(c1, c2);
		cout << cost << "\n";
		curr = next;
	}

	return 0;
}

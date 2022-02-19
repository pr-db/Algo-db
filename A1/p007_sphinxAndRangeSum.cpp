#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll a[n];
	cin >> a[0];
	for (ll i = 1; i < n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	ll t;
	cin >> t;
	while (t > 0)
	{
		ll l, r;
		cin >> l >> r;
		r--;
		l--;
		if (l == 0)
			cout << a[r]<<"\n";
		else
			cout << a[r] - a[l - 1]<<"\n";

		t--;
	}
	return 0;
}

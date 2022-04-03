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
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll xr=0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		xr ^=a[i];
	}
	xr &= (-xr);
	ll x = 0, y = 0;

	for (ll i = 0; i < n; i++)
	{
		if(a[i]&xr)
			x ^= a[i];
		else
			y ^= a[i];
	}
	if (x < y)
		cout << x << " " << y;
	else
		cout << y << " " << x;
	return 0;
}

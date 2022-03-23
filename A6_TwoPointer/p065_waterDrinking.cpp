#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1)
	{
		cout << 1 << " " << 0;
		return 0;
	}
	ll t = 0, ga = 0, gb = 0;
	for (ll i = 0, j = n - 1; ;)
	{
		ll tim = min(a[i], a[j]);
		t += tim;
		a[i] -= tim;
		a[j] -= tim;
		if(a[i]==0)
			i++;
		if (i == j)
		{
			ga = i ;
			gb = n - ga;
			break;
		}
		if(a[j]==0)
			j--;
		if (i == j)
		{
			ga = i + 1;
			gb = n - ga;
			break;
		}
	}
	cout << ga << " " << gb;
	return 0;
}

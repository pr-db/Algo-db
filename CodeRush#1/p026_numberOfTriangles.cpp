#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool predicate(vector<ll> &a,ll i,ll j,ll M)
{
	return a[i]+a[j]>a[M];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n ;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	sort(a.begin(), a.end());
	a.push_back(INT_MAX);
	for (ll i = 0; i < n;i++)
	{
		for (ll j = i + 1; j < n;j++)
		{
			ll L = j, R = n, M;
			while (L + 1 < R)
			{
				M = L + (R - L) / 2;
				if (predicate(a,i,j,M))
					L = M;
				else
					R = M;
			}
			ans += (L - j);
		}
	}
	cout << ans;
	return 0;
}

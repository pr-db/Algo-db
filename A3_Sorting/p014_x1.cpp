#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<long long> v;

ll sortbyn(ll a , ll b)
{
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	v a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	v d(n - 1), d1, d2;
	v ans;
	for (ll i = 1; i < n; i++)
	{
		d[i - 1] = (a[i] - a[i - 1]);
	}

	return 0;
}

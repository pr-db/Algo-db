#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

bool predicate(vector<ll> &a, ll sm, ll m)
{
	ll n = a.size();
	ll s = 0;
	ll i = 0;
	for (i = 0; i < n && m > 0;)
	{
		if (s + a[i] <= sm)
			s += a[i++];
		else
		{
			s = 0;
			m--;
			continue;
		}
	}
	if (i == n&&m<=n)
		return true;
	return false;
}
int main()
{
	FastIO;
	ll n, m, sum = 0;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ll l = -1, r = 2 * sum + 2, mid;
	while (l + 1 < r)
	{
		mid = l + (r - l) / 2;
		if (predicate(a, mid, m))
			r = mid;
		else
			l = mid;
		// cout << l << " " << r << "\n";
	}
	if(predicate(a,r,m))
		cout << r;
	else
		cout << -1;
	return 0;
}

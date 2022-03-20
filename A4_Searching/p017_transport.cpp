#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, c;
bool predicate(vector<ll> &a, ll M)
{
	bool ans = true;
	ll c1 = c, m1 = m, n1 = 0;
	while (n1 < n && m1 > 0)
	{
		c1 = c;
		ll n2 = n1;
		n1++;
		while (c1 > 1 && n1 < n)
		{
			n1++;
			c1--;
			if ((a[n1 - 1] - a[n2]) > M)
			{
				n1--;
				break;
			}
		}
		m1--;
	}
	if (n1 != n)
		ans = false;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> c;
	vector<ll> a;
	for (ll i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	ll ans = a[n - 1] - a[0];
	ll L = 0, R = ans + 1, M;

	while (L + 1 < R)
	{
		M = L + (R - L) / 2;
		if (predicate(a, M))
			R = M;
		else
			L = M;
	}
	cout << "\n";
	cout << L + 1;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
bool predicate(vector<vector<ll>> &a, int n, int m, int x)
{
	ll i = 0;
	ll now = a[i][0];
	n--;
	while (n > 0 && i < m)
	{
		if (now + x <= a[i][1])
			now += x;
		else
		{
			while ((i < m) && (now + x > a[i][1]))
				i++;
			if (i < m)
			{
				if ((now + x > a[i][0]) && (now + x <= a[i][1]))
					now += x;
				else if (now + x <= a[i][1])
					now = a[i][0];
			}
			else
				break;
		}
		n--;
	}
	if (n)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(m, vector<ll>(2));
	for (ll i = 0; i < m; i++)
		cin >> a[i][0] >> a[i][1];
	sort(a.begin(), a.end());

	ll l = 0, r = a[m - 1][1] - a[0][0] + 2, x;
	while (l + 1 < r)
	{
		x = l + (r - l) / 2;
		if (predicate(a, n, m, x))
			l = x;
		else
			r = x;
	}
	cout << l;
	return 0;
}

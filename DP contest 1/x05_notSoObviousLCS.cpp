#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> a;
vector<ll> b;
vector<ll> c;
int lis()
{
	int n = c.size();
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (c[i] > c[ans])
			c[++ans] = c[i];
		else
			*lower_bound(begin(c), begin(c) + ans, c[i]) = c[i];
		// cout << ans << " ";
	}
	if (c.size())
		return ans + 1;
	return 0;
}
int main()
{
	FastIO;
	int n, m;
	cin >> n >> m;
	b = vector<ll>(m);
	a = vector<ll>(n);
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = i + 1;
	}
	for (ll i = 0; i < m; i++)
	{
		cin >> b[i];
		if (mp[b[i]])
			c.push_back(mp[b[i]]);
	}

	cout << m - lis();

	return 0;
}

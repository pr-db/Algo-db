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
	unordered_map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	ll x = -1, y = -1;
	for (auto it : mp)
	{
		if (it.second % 2 && x == -1)
			x = it.first;
		else if (it.second % 2 && y == -1)
			y = it.first;
		else
			continue;
	}
	if(x<y)
		cout << x << " " << y;
	else
		cout << y << " " << x;
	return 0;
}

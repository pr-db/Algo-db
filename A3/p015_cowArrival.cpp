#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,ans=0;
	cin >> n;
	vector<pair<int, int>> c;
	for (int i = 0; i < n;i++)
	{
		ll x, y;
		cin >> x >> y;
		c.push_back(make_pair(x,y));
	}
	sort(c.begin(), c.end());
	ans += c[0].first+c[0].second;
	for (int i = 1; i < n; i++)
	{
		if(ans<c[i].first)
			ans += (c[i].first-ans);
		ans += c[i].second;
	}
	cout << ans;
	return 0;
}

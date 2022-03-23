#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return (a.second > b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, inp;
	cin >> n;

	vector<ll> v;
	for (ll i = 0; i < n; i++)
	{
		cin >> inp;
		v.push_back(inp);
	}

	unordered_map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		mp[v[i]] += 1;
	}

	vector<pair<ll, ll>> vp;
	for (auto x : mp)
	{
		vp.push_back(make_pair(x.first, x.second));
	}

	sort(vp.begin(), vp.end(), sortbysec);

	for (ll i = 0; i < vp.size(); i++)
	{
		for (ll j = 0; j < vp[i].second; j++)
		{
			cout << vp[i].first << " ";
		}
	}

	return 0;
}
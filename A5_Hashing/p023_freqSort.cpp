#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return (a.second > b.second);
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	vector<pair<ll, ll>> freq;
	freq.push_back(make_pair(a[0], 1));
	for (ll i = 1; i < n; i++)
		if (a[i] == freq[freq.size() - 1].first)
			freq[freq.size() - 1].second++;
		else
			freq.push_back(make_pair(a[i], 1));

	sort(freq.begin(), freq.end(), cmp);

	for (auto &it : freq)
		for (ll i = 0; i < it.second; i++)
			cout << it.first << " ";
	return 0;
}

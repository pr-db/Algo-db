#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define nl cout << "\n";

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.second > b.second)
		return true;
	if (a.second == b.second)
		return a.first < b.first;
	return false;
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll minpc = INT_MAX, maxn = 0, maxi = -1;
	ll ans = 0;
	vector<pair<ll, ll>> noOfBits(n);
	map<ll, ll> bitcount;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		noOfBits[i].first = a[i];
		noOfBits[i].second = log2(a[i]);
		bitcount[noOfBits[i].second]++;
	}
	sort(noOfBits.begin(), noOfBits.end(), cmp);

	for (ll i = 0; i < n; i++)
		cout << noOfBits[i].first << " " << noOfBits[i].second << "\n";
	nl;
	ll index, bc;
	for (index = 0; index < n; index++)
	{
		if (bitcount[noOfBits[index].second] > 1)
		{
			bc = bitcount[noOfBits[index].second];
			break;
		}
	}
	for (ll j = bc-1; j >=0;j--)
	{
		for (ll i = index; noOfBits[i].second == bc; i++)
		{
			
		}
	}

		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < n; j++)
			{
				// cout << a[i] << " " << a[j] << "\n";
				if (i != j)
					ans = max(ans, a[i] & a[j]);
			}
		}
	cout << ans << " ";
	ans = 0;
	for (ll i = 0; i < n; i++)
		if (i != maxi)
			ans = max(ans, a[i] & maxn);
	cout << ans;
	return 0;
}

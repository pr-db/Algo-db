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
	vector<ll> b(n);
	unordered_map<ll, ll> mp;
	ll sum = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{	cin >> a[i];
		if(a[i]==0)
			a[i] = -1;
		sum += a[i];
		b[i] = sum;
	}
	for (ll i = 0; i < n; i++)
	{
		if(b[i]==0)
			ans++;
		if(mp[b[i]])
			ans += mp[b[i]];
		if(mp[b[i]]==0)
			mp[b[i]] = 1;
		else
			mp[b[i]]++;
	}
	cout << ans;

	return 0;
}

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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	set<ll> uni;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		uni.insert(a[i]);
	}
	for (ll i = 0; i < m; i++)
	{
		cin >> b[i];
		uni.insert(b[i]);
	}
	for (auto it = uni.begin(); it!=uni.end();it++)
		cout << *it<<" ";
		return 0;
}

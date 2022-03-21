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
	vector<ll> c;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < m; i++)
		cin >> b[i];
	ll i, j;
	for ( i = 0, j = 0; i < n && j < m;)
		if(a[i]<b[j])
			c.push_back(a[i++]);
		else
			c.push_back(b[j++]);
	while(i<n)
		c.push_back(a[i++]);
	while(j<m)
		c.push_back(b[j++]);
	for(auto& it:c)
		cout << it << " ";
	return 0;
}

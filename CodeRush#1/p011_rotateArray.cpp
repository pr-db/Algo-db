#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < k;i++)
	{
		ll temp = a[0];
		a.erase(a.begin());
		a.push_back(temp);
	}
	for (ll i = 0; i < n; i++)
		cout<< a[i]<<" ";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll, ll> pos[5];
bool sortByIndex(ll a, ll b)
{
	ll f=0;
	for (ll i = 0; i < 5;i++)
		f += pos[i][a] < pos[i][b];
	return f > 2;
}
int main()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < 5; i++)
		for (ll j = 0; j < n; j++)
		{
			ll x;
			cin >> x;
			pos[i][x] = j;
			a[j] = x;
		}
	sort(a, a + n, sortByIndex);
	for (ll i = 0; i < n;i++)
		cout << a[i] << " ";

		return 0;
}
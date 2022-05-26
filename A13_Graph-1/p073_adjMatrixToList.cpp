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
	ll a[n][n];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			cin >> a[i][j];
	vector<ll> b[n];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			if (a[i][j] == 1)
				b[i].push_back(j + 1);
	for (ll i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		for (ll j = 0; j < b[i].size(); j++)
			cout << b[i][j] << " ";
		cout << "\n";
	}
	return 0;
}

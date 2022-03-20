#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll a[n][n];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			cin >> a[j][i];

	for (ll i = n-1; i >=0; i--)
	{
		for (ll j = 0; j <n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
		return 0;
}

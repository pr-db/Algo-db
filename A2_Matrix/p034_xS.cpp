#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> a[i][j];

	ll out = n * m;
	int mn = min(n, m), i, j;

	if (n == 1 && m == 1)
		cout << a[0][0];
	else
	{
		while (out>0)
		{
			for (j = i; j <= m - i - 1; j++)
			{
				cout << a[i][j] << " ";
				out--;
			}
			for (j = i + 1; j <= n - i - 1; j++)
			{
				cout << a[j][m - i - 1] << " ";
				out--;
			}
			for (j = m - i - 2; j >= i; j--)
			{
				cout << a[n - i - 1][j] << " ";
				out--;
			}
			for (j = n - i - 2; j >= i + 1; j--)
			{
				cout << a[j][i] << " ";
				out--;
			}
		}
	}
	return 0;
}

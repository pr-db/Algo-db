#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, q;
	cin >> n >> m >> q;
	ll a[n][m];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> a[i][j];
	ll b[q], c[q], i = 0, j;
	for (ll p = 0; p < q; p++)
		cin >> b[p];

	sort(b, b + q);
	for (ll p = 0; p < q; p++)
	{
		j = m - 1;
		while (i < n && j >= 0)
		{
			if (b[p] == a[i][j])
				break;
			else if (b[p] > a[i][j])
				i++;
			else
				j--;
		}
		cout << b[p] << " = " << i << " " << j << "\n";
	}
	return 0;
}

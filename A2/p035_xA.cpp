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

	ll b[q], i, j;
	for (ll p = 0; p < q; p++)
	{
		cin >> b[p];
	}

	for (ll p = 0; p < q; p++)
	{
		i = 0;
		j = m - 1;
		bool eq = false;
		while (j >= 0 && i < n)
		{
			if (b[p] == a[i][j])
			{
				eq = true;
				break;
			}

			else if (b[p] > a[i][j])
				i++;
			else
				j--;
		}
		if (eq)
		{
			cout << i << " " << j << "\n";
		}
	}
	return 0;
}
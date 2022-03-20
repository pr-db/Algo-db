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
	int mini = 0, minj = 0, maxi = n, maxj = m;
	if (n == 1 && m == 1)
		cout << a[0][0];
	else
	{

		while (out > 0)
		{
			int i = mini, j = minj;
			while (j < maxj - 1 && out > 0)
			{
				cout << a[i][j] << " ";
				j++;
				out--;
			}
			maxj--;
			while (i < maxi - 1 && out > 0)
			{
				cout << a[i][j] << " ";
				out--;
				i++;
			}
			maxi--;
			while (j > minj && out > 0)
			{
				cout << a[i][j] << " ";
				out--;
				j--;
			}
			minj++;
			while (i > mini && out > 0)
			{
				cout << a[i][j] << " ";
				out--;
				i--;
			}
			mini++;
		}
	}
	return 0;
}


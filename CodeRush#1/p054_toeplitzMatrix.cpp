#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> a[i][j];
	ll i = 0, j = m - 1, c = 1;
	while (j>=0 && c)
	{
		i = 0;
		ll temp = a[i][j], k = j,l=i;
		for (ll p = 0; (p < m - j)&&(p<n-i); p++)
		{
			if (a[l++][k++] != temp)
			{
				c = 0;
				break;
			}
		}
		j--;
	}
	i = n-1, j = 0;
	while (i>0 && c)
	{
		j = 0;
		ll temp = a[i][j], k = j,l=i;
		for (ll p = 0; (p < n - i)&&(p<m-j); p++)
		{
			if (a[l++][k++] != temp)
			{
				c = 0;
				break;
			}
		}
		i--;
	}
	
	cout << c;
	return 0;
}

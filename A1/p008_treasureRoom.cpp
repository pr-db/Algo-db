#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<long long int> vll;
int main()
{
	ll n, w;
	cin >> n >> w;
	ll a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int i, j, k;
	for (i = 0; i < n; i++)
		if (a[i] > w)
			break;
	for (j = 0, k = i - 1; j < k;)
	{
		if (a[j] + a[k] == w)
			break;

		else if (a[j] + a[k] < w)
		{
			j++;
			continue;
		}
		else
		{
			k--;
			continue;
		}
	}
	int l = -1, r = -1;
	for (i = 0; i < n; i++)
	{
		if (l >= 0 && r >= 0)
		{
			cout << l + 1 << " " << r + 1;
			break;
		}
		if (b[i] == a[j])
		{
			l = i;
			continue;
		}
		if (b[i] == a[k])
		{
			r = i;
			continue;
		}
	}
	if (l < 0 || r < 0)
	{
		cout << -1;
	}
	return 0;
}

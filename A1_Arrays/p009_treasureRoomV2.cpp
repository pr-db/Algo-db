#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<long long int> vll;
int main()
{
	ll n, sum;
	cin >> n >> sum;
	ll a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int i, j, k;
	for (i = 0; i < n; i++)
		if (a[i] > sum)
			break;
	int x, c = 0;
	for (x = 0; x < i; x++)
	{
		int w = sum - a[x];
		for (j = 0, k = i - 1; j < k;)
		{
			if (j == x)
			{
				j++;
				continue;
			}
			if (k == x)
			{
				k--;
				continue;
			}
			if (a[j] + a[k] == w)
			{

				c = 1;
				break;
			}
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
		if (c == 1)
			break;
	}
	int l = -1, m = -1, r = -1;
	for (i = 0; i < n; i++)
	{
		if (l >= 0 && r >= 0 && m >= 0)
		{
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
		if (b[i] == a[x])
		{
			m = i;
			continue;
		}
	}
	if (l < 0 || r < 0 || m < 0)
	{
		cout << -1;
	}
	else
	{
		cout << l + 1 << " " << m + 1 << " " << r + 1;
	}

	return 0;
}

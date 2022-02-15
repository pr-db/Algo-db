#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int c = 0;
	if (a[0] != 1)
	{
		cout << 1;
		c = 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1)
				continue;
			else
			{
				cout << a[i-1]+1;
				c = 2;
				break;
			}
		}
	}
	if(c==0)
	{
		cout << a[n - 1] + 1;
	}
	return 0;
}

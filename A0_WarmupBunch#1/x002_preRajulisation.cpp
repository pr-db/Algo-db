#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	int d;
	cin >> d;
	int a[d];
	for (int i = 0; i < d; i++)
		cin >> a[i];
	ll n;
	cin >> n;
	int base = 10 - d;
	int dig[base];
	dig[0] = 0;
	for (int i = 1, j = 1, k = 0; i < base; i++, j++)
	{
		if (j != a[k])
			dig[i] = j;
		else
		{
			while (j == a[k])
			{
				j++;
				k++;
			}
			dig[i] = j;
		}
	}

	ll div, rem;
	string ans;
	while (n != 0)
	{
		div = n / base;
		rem = n % base;
		ans.append(to_string(dig[rem]));
		n = div;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}

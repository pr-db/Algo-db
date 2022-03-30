#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
int main()
{
	FastIO;
	ll n, k, c = 0;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0, j = 2; i < n - 2 && i < j&&j<n;)
	{
		cout << i << " " << j << "  " << a[j] - a[i] << ",  ";
		if (a[j] - a[i] <= k)
		{
			c += j - i - 1;
			if (j < n - 1)
				j++;
			else
			{
				// cout << "hi";
				i++;
				j = i + 2;
				if(j>n-1)
					break;
			}
		}
		else 
		{
			i++;
			j = i + 2;
			if (j > n - 1)
				break;
		}
		cout << c << "\n";
	}
	cout << c;
	return 0;
}

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
	vector<ll> s(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += i + 1;
		s[i] += sum;
		// cout << s[i] << " ";
	}
	cout << "\n";
	for (ll i = 0, j = n - 1; i < n - 2 && i + 1 < j;)
	{
		// cout << i << " " << j << "  " << a[j] - a[i] << ",  ";
		if (a[j] - a[i] <= k)
		{
			c += s[j - i - 2];
			// cout << j - i - 2 << "  ";
			i++;
			j = n - 1;
		}
		else if (j > i + 2)
				j--;
		else
			break;
		// cout << c << "\n";
	}
	cout << c;
	return 0;
}

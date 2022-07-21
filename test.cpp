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
	ll n, k;
	cin >> n ;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll s = 0,e = n;
	while (s+1 < e)
	{
		int mid = (s + e) / 2;
		if (a[mid] == -1)
		{
			e = mid ;
		}
		else
		{
			s = mid;
		}
	}
	cout << e;
	return 0;
}

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
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> pa(n + 1);
	ll sum = 0,s=n+1,fsum=0;
	for (ll i = 0; i < n; i++)
	{	cin >> a[i];
		sum += a[i];
		pa[i + 1] += sum;
	}
	sum = 0;
	ll i, j;
	for (i = 1, j = 1; i <= j && i <= n&&j<=n;)
	{
		ll snow = j - i + 1;
		sum = pa[j] - pa[i-1];
		// cout <<i<<" "<<j<<" "<< sum << "\n";
		if(sum<k)
			j++;
		else if(sum>=k)
		{
			s = min(s, snow);
			fsum = sum;
			i++;
		}
	}
	// cout << sum << "\n";
	if (fsum >= k)
		cout
			<< s;
	else
		cout << -1;
	return 0;
}

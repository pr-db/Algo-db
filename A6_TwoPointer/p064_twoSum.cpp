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
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int c = 0;
	for (ll i = 0, j = n - 1; i < j;)
		if(a[i]+a[j]==k)
		{
			c=1;
			break;
		}
		else if(a[i]+a[j]>k)
			j--;
		else
			i++;
	cout << c;
	return 0;
}

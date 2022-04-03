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
	ll n;
	cin >> n ;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0;
	for (ll i = 0; i < n;i++)
	sum += a[i] * (n - 2 * i - 1);
	cout << sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<vector<ll>> dp;
vector<ll> a;

ll price(ll l, ll r)
{
	if (l > r)
		return 0;
	if (dp[l][r] >= 0)
		return dp[l][r];
	ll y = dp.size() - (r - l);
	return dp[l][r] = max(y * a[l] + price(l + 1, r), y * a[r] + price(l, r - 1));
}
int main()
{
	FastIO;
	ll n, k;
	cin >> n;
	a = vector<ll>(n);
	dp = vector<vector<ll>>(n, vector<ll>(n, -1));
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	cout << price(0, n - 1);

	return 0;
}

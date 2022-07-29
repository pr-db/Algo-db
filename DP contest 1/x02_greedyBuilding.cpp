#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<vector<ll>> dp;
vector<ll> a;
ll price(ll &c, ll n, ll sum)
{
	if (n < 0)
		return INT_MAX;
	if (sum == 0)
	{
		c = 1;
		return 0;
	}
	if (dp[n][sum] >= 0)
		return dp[n][sum];
	if (a[n] <= sum)
		return dp[n][sum] = min(price(c, n - 1, sum), 1 + price(c, n, sum - a[n]));
	return dp[n][sum] = price(c, n - 1, sum);
}
int main()
{
	FastIO;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k, c = 0;
		cin >> n >> k;
		a = vector<ll>(n);
		dp = vector<vector<ll>>(n, vector<ll>(k + 1, -1));
		for (ll i = 0; i < n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());
		ll ans = price(c, n - 1, k);

		// for (ll i = 0; i < n; i++)
		// {
		// 	for (ll j = 0; j <= k; j++)
		// 		cout << dp[i][j] << " ";
		// 	cout << "\n";
		// }
		if (c)
			cout << ans;
		else
			cout << -1;
		cout<< "\n";
	}

	return 0;
}

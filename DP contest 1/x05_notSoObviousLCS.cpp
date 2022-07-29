#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<vector<ll>> dp;
vector<ll> a;
ll n;
ll lis(ll i, ll j)
{
	if (i == n)
		return 0;
	if (dp[i][j] >= 0)
		return dp[i][j];

	if (a[i] > a[j])
		return dp[i][j] = max(dp[i][j], 1 + lis(i + 1, i));
	return dp[i][j] = max(dp[i][j], lis(i + 1, j));
}
int main()
{
	FastIO;
	cin >> n;
	a = vector<ll>(n);
	dp = vector<vector<ll>>(n, vector<ll>(n, -1));
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	cout << lis(0, 0);

	return 0;
}

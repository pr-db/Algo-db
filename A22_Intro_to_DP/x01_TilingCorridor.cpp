#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> dp;
ll countStairs(ll n)
{
	if(n==0 || n==1||n==2)
		return n;
	if(dp[n])
		return dp[n];
	return dp[n] = countStairs(n - 1) % 1000000007 + countStairs(n - 2) % 1000000007;
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	dp = vector<ll>(n + 1);
	ll ans = countStairs(n) % 1000000007;
	cout << ans;
	return 0;
}

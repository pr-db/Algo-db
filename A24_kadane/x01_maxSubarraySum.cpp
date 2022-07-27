
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
vector<int> dp;
vector<int> a;
int mx = INT_MIN;
int count(int i)
{
	// base
	if (i < 0)
		return 0;
	// memo
	if (dp[i] >= 0)
		return dp[i];
	// transition
	dp[i] = max(count(i - 1) + a[i], a[i]);
	mx = max(mx, dp[i]);
	return dp[i];
}
int main()
{
	FastIO;
	int n;
	cin >> n;
	a = vector<int>(n);
	dp = vector<int>(n, -1);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	count(n - 1);
	cout << mx;
	return 0;
}

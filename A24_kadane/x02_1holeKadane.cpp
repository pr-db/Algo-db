
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int>> dp(n, vector<int>(2, -1));
	dp[0][0] = a[0];
	dp[0][1] = a[0];
	int mx = max(dp[0][0], dp[0][1]);
	int ans = INT_MIN;
	ans = max(mx, ans);

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
		mx = max(dp[i][0], dp[i][1]);
		ans = max(mx, ans);
	}
		cout << ans;
	return 0;
}


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
	vector<int> dp(n, -1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = a[0];
	int mx = INT_MIN;
	mx = max(dp[0], mx);

	for (int i = 1; i < n; i++)
	{
		dp[i] = a[i] + max(0, dp[i - 1]);
		mx = max(dp[i], mx);
	}

	cout << mx;
	return 0;
}

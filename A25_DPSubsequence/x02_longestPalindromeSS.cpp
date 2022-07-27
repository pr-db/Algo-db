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
	string s,t;
	cin >> s ;
	int n = s.size();
	t = s;
	reverse(t.begin(), t.end());
	vector<vector<int>> dp(n, vector<int>(n, -1));

	dp[0][0] = (s[0] == t[0]);
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] || (s[i] == t[0]);
	for (int i = 1; i < n; i++)
		dp[0][i] = dp[0][i - 1] || (s[0] == t[i]);

	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			if (s[i] == t[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	cout << dp[n - 1][n - 1];
	return 0;
}

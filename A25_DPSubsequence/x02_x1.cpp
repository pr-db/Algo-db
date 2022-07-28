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
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));

	for (int l = n - 1; l >= 0; l--)
	{
		dp[l][l] = 1;
		for (int r = l + 1; r < n; r++)
		{
			if (s[l] == s[r])
				dp[l][r] = dp[l + 1][r - 1] + 2;
			else
				dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	cout << dp[0][n - 1];
	return 0;
}

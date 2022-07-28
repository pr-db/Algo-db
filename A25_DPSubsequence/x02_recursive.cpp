#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
vector<vector<int>> dp;
string s;
int pal(int l, int r)
{
	if (l > r)
		return 0;
	if (l == r)
		return dp[l][r] = 1;
	if (dp[l][r] >= 0)
		return dp[l][r];
	if (s[l] == s[r])
		return dp[l][r] = pal(l + 1, r - 1) + 2;
	return dp[l][r] = max(pal(l + 1, r), pal(l, r - 1));
}

int main()
{
	FastIO;
	cin >> s;
	int n = s.size();
	dp = vector<vector<int>>(n, vector<int>(n, -1));
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	cout << pal(0, n - 1);
	return 0;
}

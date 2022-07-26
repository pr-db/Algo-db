#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<int> a;
vector<vector<int>> dp;

int choco(int i, int n)
{
	if (i < 0)
		return 0;
	if (n == 0)
		return 0;
	if (dp[i][n] >= 0)
		return dp[i][n];
	if (n - i - 1 < 0)
		return dp[i][n] = choco(i - 1, n);

	return dp[i][n] = max(a[i] + choco(i , n - i - 1), choco(i - 1, n));
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		a = vector<int>(n);
		dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << choco(n - 1, n);
		cout << "\n";
	}
	return 0;
}
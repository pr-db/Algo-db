#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<int> dp;
int n;
int fibo(int k)
{
	if(dp[k])
		return dp[k];
	return dp[k] = fibo(k-1) + fibo(k-2);
}

int main()
{
	FastIO;
	cin >> n;	
	dp = vector<int>(n+1);
	if (n == 1 || n == 2)
		cout << 1;
	else
	{
		dp[1] = 1;
		dp[2] = 1;
		cout<< fibo(n);
	}

	return 0;
}

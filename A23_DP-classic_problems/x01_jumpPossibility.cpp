#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> a;
vector<vector<ll>> dp;
bool jump(ll j, ll sum)
{
	if (sum == 0)
		return true;
	if (j < 0)
		return false;
	if(dp[j][sum]>=0)
		return dp[j][sum];
	if (sum - a[j] < 0)
		return dp[j][sum] = jump(j - 1, sum);
	return dp[j][sum] = (jump(j - 1, sum) or jump(j - 1, sum - a[j]));
}

int main() 
{
	FastIO;
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		a = vector<ll>(n);
		dp = vector<vector<ll>>(n, vector<ll>(k+1, -1));
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		if (jump(n - 1, k))
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;
}

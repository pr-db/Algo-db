
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll a[n][n];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			cin >> a[i][j];
	ll sumr[n] = {0}, sumc[n] = {0};
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			sumr[i] += a[i][j];
			sumc[i] += a[j][i];
		}
	}
	sort(sumr, sumr + n);
	sort(sumc, sumc + n);
	int ans = 0;
	for (ll i = 0; i < n; i++)
		ans += abs(sumr[i] - sumr[n / 2]);
	for (ll i = 0; i < n; i++)
		ans += abs(sumc[i] - sumc[n / 2]);
	cout << ans;
	return 0;
}

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
	ll n;
	cin >> n;
	ll ans = 0;
	while (n)
	{
		if (n % 2)
			ans++;
		n /= 2;
	}
	cout << ans;
	return 0;
}

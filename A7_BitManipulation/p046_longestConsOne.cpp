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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> a;

		while (n)
		{
			a.push_back(n % 2);
			n /= 2;
		}
		// for (ll i = 0; i < a.size(); i++)
		// {
		// 	cout << a[i] << " ";
		// }
		// cout << "  ";
		ll ans = 0, ansnow = 0;

		for (ll i = 0; i < a.size(); i++)
			if (a[i])
				ansnow++;
			else
			{
				ans = max(ans, ansnow);
				ansnow = 0;
			}
		ans = max(ans, ansnow);
		cout << ans << "\n";
	}
	return 0;
}

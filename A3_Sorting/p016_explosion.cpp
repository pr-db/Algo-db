#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 1;
	for (ll i = 0; i < n; i++)
	{
		ll maxi = ans;
		ans = 1;
		ll j = i + 1, k = i - 1, ji = i, ki = i;
		ll f1 = 1, f2 = 1;
		for (ll t = 1;; t++)
		{
			if ((a[j] <= a[ji] + t) && j < n && f1)
				for (; (a[j] <= a[ji] + t) && j < n; j++, ans++);
			else
				f1 = 0;
			if ((a[k] >= a[ki] - t) && k >= 0 && f2)
				for (; (a[k] >= a[ki] - t) && k >= 0; k--, ans++);
			else
				f2 = 0;
			if (f1 == 0 && f2 == 0)
				break;
			ji = j - 1;
			ki = k + 1;
		}
		ans = max(maxi, ans);
	}
	cout << ans;

	return 0;
}

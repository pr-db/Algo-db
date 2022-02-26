#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	v a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll t = 1, ans = 1, now = 0, next = 0;
	for (int i = 0,j=1; i < n;)
	{
		if (a[j] <= a[i] + t and j<n)
		{
			while(a[j] <= a[i] + t and j<n)
			{
				ans++;
				//cout << a[j] << " ";
				j++;
			}
			i = j-1;
			t++;
			cout << t << " ";
			continue;
		}
		else
			break;
		
	}
	cout << ans;
	return 0;
}

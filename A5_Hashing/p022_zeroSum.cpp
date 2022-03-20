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
	vector<ll> a(n);
	vector<ll> pa(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	pa[0] = a[0];
	for (ll i = 1; i < n; i++)
		pa[i] += pa[i - 1] + a[i];
	unordered_map<ll, ll> ct;
	int cs = 0;
	for (ll i = 0; i < n; i++)
	{
		ct[pa[i]]++;
		if (ct[pa[i]] > 1)
		{
			cs = 1;
			break;
		}
	}
	if (cs)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

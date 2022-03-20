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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	unordered_map<ll, ll> uni;
	for (ll i = 0; i < k; i++)
		uni[a[i]]++;
	cout << uni.size() << " ";
	for (ll i = k; i < n; i++)
	{
		uni[a[i - k]]--;
		if (uni[a[i - k]] == 0)
			uni.erase(a[i - k]);
		uni[a[i]]++;
		cout << uni.size() << " ";
	}
	return 0;
}

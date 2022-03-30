#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

// 1 2 3 4 5 7

int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> a(n);
	set<ll> cons;
	for (ll i = 0; i < n; i++) 
	{
		cin >> a[i];
		cons.insert(a[i]);
	}
	ll m = 1, mx = 1;
	vector<ll> v;
	for (auto &it : cons)
		v.push_back(it);

	for (ll i = 1; i < v.size(); i++){
		if (v[i] == v[i - 1] + 1)
			m++;
		else
		{

			m = 1;
		}
		mx = max(mx, m);
	}
		

	cout << mx;
	return 0;
}

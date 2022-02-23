#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v;
typedef vector<vector<int>> vv;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n ;
	v a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	v dif(n-1);
	for (int i = 0; i < n-1;i++)
	{
		dif[i] = a[i + 1] - a[i];
	}
		return 0;
}

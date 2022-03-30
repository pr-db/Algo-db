#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

int main()
{
	FastIO;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// unordered_set<ll> st;
	// for (ll i = 0; i < n;i++){
	// 	st.insert(a[i]);
	// }

	// vector<ll> v;
	// for(auto x:st){
	// 	v.push_back(x);
	// }

	// ll m = v.size();
	// // cout << m << "\n";
	// sort(v.begin(), v.end());

	// int sm = 1;
	// int ans = 1;

	// for (ll i = 1; i < m;i++){
	// 	if(v[i]==v[i-1]+1){
	// 		sm += 1;
	// 	}
	// 	else{
	// 		sm = 1;
	// 	}
	// 	ans = max(ans, sm);
	// }

	// cout << ans << "\n";

	// ll m = 1, mx = 1;

	// for (ll i = 1; i < a.size(); i++)
	// 	if (a[i] == a[i - 1]+1)
	// 		m++;
	// 	else if(a[i]==a[i-1])
	// 		continue;
	// 	else
	// 	{
	// 		mx = max(mx, m);
	// 		m = 1;
	// 	}

	// cout << mx;

	return 0;
}

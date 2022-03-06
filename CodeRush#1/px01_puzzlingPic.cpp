#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class pic
{
	ll num;
	ll index;
};
bool sortByIndex(vector<ll> &a,ll bi,ll bj)
{
	auto iti = find(a.begin(), a.end(), bi);
	auto itj = find(a.begin(), a.end(), bj);
	ll i = iti - a.begin();
	ll j = itj - a.begin();
	return i < j;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n ;
	pic a[5][n];
		

	return 0;
}

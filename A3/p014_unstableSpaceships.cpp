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
	cin >> n;
	v a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	v dif(n - 1);
	for (int i = 0; i < n - 1; i++)
		dif[i] = a[i + 1] - a[i];
	ll fmax = *max_element(dif.begin(), dif.end()), smax = 0, fc = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (dif[i] > smax && dif[i] != fmax)
			smax = dif[i];
		else if (dif[i] == fmax)
			fc++;
	}
	if (fc > 1)
		smax = fmax;
	v nb(4);
	for (int i = 0; i < n - 1; i++)
	{
		if(dif[i]==fmax)
		{
		if(i>0)
			nb[0] = dif[i - 1];
		else
		{
			/* code */
		}
		
	}
	return 0;
}

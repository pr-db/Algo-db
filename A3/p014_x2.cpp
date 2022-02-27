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
	v d(n - 1), d1, d2;
	v ans;
	for (ll i = 1; i < n; i++)
	{
		d[i - 1] = (a[i] - a[i - 1]);
	}
	d1.push_back(a[0]);
	for (ll i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)
			d2.push_back(d[i]);
		else
			d1.push_back(d[i]);
	}
	if ((n - 1) % 2 == 0)
		d2.push_back(a[n - 1]);
	else
		d1.push_back(a[n - 1]);

	ll f1 = *max_element(d1.begin(), d1.end()), s1 = 0, fc1 = 0;
	for (ll i = 0; i < d1.size(); i++)
	{
		if (d1[i] > s1 && d1[i] != f1)
			s1 = d1[i];
		else if (d1[i] == f1)
			fc1++;
	}
	if (fc1 > 1)
		s1 = f1;

	ll f2 = *max_element(d2.begin(), d2.end()), s2 = 0, fc2 = 0;
	for (ll i = 0; i < d2.size(); i++)
	{
		if (d2[i] > s2 && d2[i] != f2)
			s2 = d2[i];
		else if (d2[i] == f2)
			fc1++;
	}
	if (fc2 > 1)
		s2 = f2;

	return 0;
}


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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = INT_MIN;
	int cs = 0;
	for (int i = 0; i < n; i++)
	{
		cs += a[i];
		mx = max(mx, cs);
		if (cs < 0)
			cs = 0;
	}

	cout << mx;
	return 0;
}

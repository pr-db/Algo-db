
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
	int ans = n * (n + 1) / 2;
	n /= 4;
	while (n)
	{
		ans += n * (n + 1) / 2;
	}
	cout << ans;
	return 0;
}

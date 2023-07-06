#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<vector<int>> ans;

void toh(int n, int a, int b, int c)
{
	if (n == 1)
	{
		ans.push_back({{n, a, b}});
		return;
	}
	toh(n - 1, a, c, b);
	ans.push_back({{n, a, b}});
	toh(n - 1, c, b, a);
}
int main()
{
	FastIO;
	ll n;
	cin >> n;
	toh(n, 1, 2, 3);
	cout << ans.size()<<"\n";
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	return 0;
}

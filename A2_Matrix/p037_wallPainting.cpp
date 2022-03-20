#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int x = 1000;
	cin >> n >> k;
	int a[n][4], l = 0, b = 0;
	vector<vector<ll>> wall(1000, vector<ll>(1000, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
		wall[a[i][0]][a[i][1]] += 1;
		wall[a[i][0]][a[i][3]] += -1;
		wall[a[i][2]][a[i][3]] += 1;
		wall[a[i][2]][a[i][1]] += -1;
		l = max(l, a[i][3]);
		b = max(b, a[i][2]);
	}
	l++;
	b++;
	for (int i = 1; i < b; i++)
		wall[0][i] += wall[0][i - 1];

	for (int i = 1; i < l; i++)
		wall[i][0] += wall[i - 1][0];

	for (int i = 1; i < l; i++)
		for (int j = 1; j < b; j++)
			wall[i][j] += wall[i - 1][j] + wall[i][j - 1] - wall[i - 1][j - 1];

	int ans = 0;
	
	for (int i = 0; i < l; i++)
		for (int j = 0; j < b; j++)
			if (wall[i][j] == k)
				ans++;
	cout << ans;
	return 0;
}

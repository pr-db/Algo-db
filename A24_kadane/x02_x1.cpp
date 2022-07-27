
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
	int prev_nonchosen = a[0];
	int prev_chosen = a[0];
	int cur_nonchosen;
	int cur_chosen;
	int mx = max(prev_chosen, prev_nonchosen);
	int ans = INT_MIN;
	ans = max(mx, ans);

	for (int i = 1; i < n; i++)
	{
		cur_nonchosen = max(prev_nonchosen + a[i], a[i]);
		cur_chosen = max(prev_nonchosen, prev_chosen + a[i]);
		mx = max(cur_chosen, cur_nonchosen);
		ans = max(mx, ans);
		prev_chosen = cur_chosen;
		prev_nonchosen = cur_nonchosen;
	}
	cout << ans;
	return 0;
}

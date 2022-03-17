#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define MAX 20000

ll A[MAX];
map<ll, ll> pos[5];

bool cmp(ll a, ll b)
{
	ll f = 0;
	for (ll i = 0; i < 5;i++)
	{
		f += pos[i][a] < pos[i][b];
	}
	return f > 2;
}

int main()
{
	FastIO;
	ll n;
	cin >> n;
	for (ll i = 0; i < 5;i++)
	{
		for (ll j = 0; j < n;j++)
		{
			ll x;
			cin >> x;
			pos[i][x] = j;
			A[j] = x;
		}
	}
	sort(A, A + n, cmp);
	for (ll i = 0; i < n;i++)
		cout << A[i] << " ";
}
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
	
	set<ll> s;
	for (ll i = 0; i < 10;i++)
		s.insert(i);

	// ll n = (s.find(3) - s.begin());
	if(s.find(9)!=s.end())
		cout << 1;
	else
		cout << 0;

	return 0;
}

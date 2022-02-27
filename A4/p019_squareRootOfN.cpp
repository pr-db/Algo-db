#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
ll predicate(ll X)
{
	return pow(X,2) > n;
}
double predicate1(double X)
{
	return pow(X, 2) > n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll L = 0, R = n,M,steps=150;
	while(L+1<R)
	{
		M = L + (R - L) / 2;
		if(predicate(M)==1)
			R = M;
		else
			L = M;
	}
	double L1=L,R1=L+1,M1;
	while (steps--)
	{
		M1 = L1 + (R1 - L1) / 2;
		if (predicate1(M1) == 1)
			R1 = M1;
		else
			L1 = M1;
	}
	cout.precision(17);
	cout<<fixed<<L1;

	return 0;
}		

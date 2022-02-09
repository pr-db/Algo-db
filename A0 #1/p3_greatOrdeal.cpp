#include <bits/stdc++.h>

using namespace std;
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	long long int a, b, c;
	cin >> a >> b >> c;
	long long int d[3] = {abs(b - a), abs(c - b), abs(c - a)};
	sort(d, d + 3);

	long long int mini, maxi;
	if (d[0] == d[1] == 1)
	{
		mini = 0;
		maxi = 0;
	}
	else if(d[1]==2)
	{
		mini = 1;
		maxi = 1;
	}
	else if (d[0] == 2) 
	{
		mini = 1;
		maxi = d[1] - 1;
	}
	else
	{
		mini = 2;
		maxi = d[1] - 1;
	}
	cout << mini << "\n"
		 << maxi;

	return 0;
}

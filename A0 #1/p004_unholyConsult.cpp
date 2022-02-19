#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int dn[2][n], dm[2][m], d1[100],d2[100];
	int j = 0,k=0;
	for (int i = 0; i < n; i++)
	{
		cin >> dn[0][i] >> dn[1][i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> dm[0][i] >> dm[1][i];
	}
	int sumn = 0,summ=0;
	for (int i = 0; i < n; i++)
	{
		sumn += dn[0][i];
		for (; j < sumn; j++)
		{
			d1[j] = dn[1][i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		summ += dm[0][i];
		for (; k < summ; k++)
		{
			d2[k] = dm[1][i];
		}
	}
	int maxi = 0;
	for (int i = 0; i < 100;i++)
	{
		maxi = max(maxi, d2[i] - d1[i]);
	}
	cout << maxi;

	return 0;
}

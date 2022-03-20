#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> row(n);
	int k = 0;
	for (int i = 0; i < n * n; i += n)
	{
		for (int j = i; j < i + n; j++)
		{
			row[k] += arr[j];
		}
		k++;
	}
	int rowMax = *max_element(row.begin(), row.end()), rowSum = 0;
	for (int i = 0; i < n; i++)
	{
		rowSum += row[i];
	}
	cout << rowMax - rowSum << endl;
	return 0;
}
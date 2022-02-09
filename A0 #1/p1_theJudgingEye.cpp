#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y, a, b;
	int n = 3;
	int d[3];
	cin >> x >> y >> a >> b;

	d[0] = abs(y - x);
	d[1] = abs(abs(y - b) + abs(x - a));
	d[2] = abs(abs(y - a) + abs(x - b));
	int dist = *min_element(d, d + 3);
	cout << dist;
	return 0;
}

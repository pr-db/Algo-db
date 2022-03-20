#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x11, y11, x12, y12;
	int x21, y21, x22, y22;

	cin >> x11 >> y11 >> x12 >> y12;
	cin >> x21 >> y21 >> x22 >> y22;

	int d[8];
	d[0] = abs(x22 - x11);
	d[1] = abs(x21 - x12);
	d[2] = abs(y21 - y12);
	d[3] = abs(y22 - y11);

	d[4] = abs(x12 - x11);
	d[5] = abs(x22 - x21);
	d[6] = abs(y11 - y12);
	d[7] = abs(y22 - y21);


	int a = pow(*max_element(d, d + 8), 2);
	cout << a;

	return 0;
}

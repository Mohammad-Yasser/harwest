#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2)
		cout << x1 + y2 - y1 << ' ' << y1 << ' ' << x2 + y2 - y1 << ' ' << y2;
	else if (y1 == y2)
		cout << x1 << ' ' << y1 + x2 - x1 << ' ' << x2 << ' ' << y2 + x2 - x1;
	else if (abs(y2 - y1) == abs(x2 - x1))
		cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
	else
		cout << -1;

}

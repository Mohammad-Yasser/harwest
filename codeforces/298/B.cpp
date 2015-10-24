#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t, x1, y1, x2, y2;
	cin >> t >> x1 >> y1 >> x2 >> y2;

	char c;

	for (int i = 1; i <= t; ++i) {
		cin >> c;
		x1 += (c == 'E' && x1 < x2) - (c == 'W' && x1 > x2);
		y1 += (c == 'N' && y1 < y2) - (c == 'S' && y1 > y2);
		if (x1 == x2 && y1 == y2) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int h1, h2, a, b;
	cin >> h1 >> h2 >> a >> b;
	h1 += a * 8;
	if (h1 >= h2) {
		cout << 0;
		return 0;
	}
	if (a <= b) {
		cout << -1;
		return 0;
	}
	a *= 12, b *= 12;
	cout << (h2 - h1 + a - b - 1) / (a - b);

}

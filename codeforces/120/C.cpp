#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	while (cin >> n) {
		for (int i = 0; i < 3; ++i)
			if (n - k >= 0)
				n -= k;
		ans += n;
	}
	cout << ans;
}

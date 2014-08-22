#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int nmb = 0;
		int tmp = i;
		for (int j = 2; j * j <= tmp; ++j)
			if (tmp % j == 0) {
				++nmb;
				while (tmp % j == 0)
					tmp /= j;
			}
		nmb += bool(tmp - 1);
		ans += nmb == 2;
	}
	cout << ans;

}

#include <bits/stdc++.h>

using namespace std;
int n, q;

inline void norm(int &x) {
	if (x < 0) x += n;
	if (x > n) x -= n;
}
const int N = 1000006;
int ans[N];

int main() {
	scanf("%d %d", &n, &q);
	int one = 1, two = 2;
	while (q--) {
		int x;
		scanf("%d", &x);
		if (x == 2)
			one += 2 * (one & 1) - 1, two += 2 * (two & 1) - 1;
		else {
			int y;
			scanf("%d", &y);
			if (y < 0) y += n;
			one += y;
			two += y;
		}
		if (one > n) one -= n;
		if (two > n) two -= n;
	}

	ans[one] = 1, ans[two] = 2;
	for (int i = one + 2 - n * (one + 2 > n), j = 3; i != one; i += 2, i -= n * (i > n), j += 2)
		ans[i] = j;

	for (int i = two + 2 - n * (two + 2 > n), j = 4; i != two; i += 2, i -= n * (i > n), j += 2)
		ans[i] = j;

	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);

}

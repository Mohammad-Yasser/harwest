#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

int to[N];

int n, k;

bool vis[N];

int p[N];

const int MOD = 1000000007;

int main() {

	cin >> n >> k;

	if (k == 0) {
		int ans = 1;
		for (int i = 1; i < n; ++i)
			ans = 1LL * ans * n % MOD;
		cout << ans;
		return 0;
	}

	p[0] = 1;

	for (int i = 1; i <= n; ++i)
		p[i] = 1LL * p[i - 1] * k % n;

	for (int i = 0; i < n; ++i)
		to[i] = 1LL * k * i % n;

	int ans = 1;

	for (int i = 0; i < n; ++i)
		if (!vis[i]) {
			int size = 1, curr = i;
			vis[i] = 1;
			while (!vis[to[curr]])
				curr = to[curr], vis[curr] = 1, ++size;
			if (p[size] == 1) ans = 1LL * ans * n % MOD;
		}

	cout << ans;
}

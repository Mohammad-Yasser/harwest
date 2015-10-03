#include <bits/stdc++.h> 
using namespace std;

int p[1001], acc[1001][1001];

bool vis[1001];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];

	int cur = 0, ans = 0;

	bool b = 0;

	while (cur < n) {

		if (!b) {
			for (int i = 0; i < n; ++i)
				if (!vis[i] && cur >= p[i]) ++cur, vis[i] = 1;
		}
		else {
			for (int i = n - 1; i >= 0; --i)
				if (!vis[i] && cur >= p[i]) ++cur, vis[i] = 1;
		}

		b = !b;
		ans += (cur < n);
	}

	cout << ans;
}

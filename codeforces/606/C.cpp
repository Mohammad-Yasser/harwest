#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 100005;
int pos[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		pos[p] = i;
	}

	int mx = 0;


	for (int i = 1; i <= n;) {
		int cnt = 1, p = pos[i];
		while (pos[i + 1] > pos[i])
			++i, ++cnt;
		++i;
		mx = max(mx, cnt);
	}

	cout << n - mx;

}

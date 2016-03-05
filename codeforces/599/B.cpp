#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int f[N], b[N], a[N];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		if (f[tmp])
			f[tmp] = -1;
		else
			f[tmp] = i;
	}

	bool imp = 0, amb = 0;

	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		if (f[tmp] == -1)
			amb = 1;
		else if (!f[tmp]) imp = 1;
		a[i] = f[tmp];
	}

	if (imp)
		cout << "Impossible";
	else if (amb)
		cout << "Ambiguity";
	else {
		cout << "Possible\n";
		for (int i = 0; i < m; ++i)
			cout << a[i] << ' ';
	}

	return 0;
}

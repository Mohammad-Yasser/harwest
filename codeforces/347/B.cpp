#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c = 0;
	cin >> n;
	int a[n];
	bool b = 0;
	for (int i = 0; i < n; cin >> a[i++])
		;
	for (int i = 0; i < n; c += a[i] == i, ++i)
		if (a[i] != i && a[a[i]] == i)
			b = 1;
	cout << min(n, c + 2 * b + 1 * !b);
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2) {
		if (n < 5) {
			cout << "NO";
			return 0;
		}
		int tmp = 0;
		cout << "YES\n3 - 2 = 1\n";
		for (int i = 6; i <= n; i += 2, ++tmp)
			cout << i + 1 << " - " << i << " = 1\n";
		while (tmp--)
			cout << "1 * 1 = 1\n";
		cout << "5 + 1 = 6\n6 * 4 = 24\n24 * 1 = 24";
	} else {
		if (n < 4) {
			cout << "NO";
			return 0;
		}
		cout << "YES\n";
		int tmp = 0;
		for (int i = 5; i <= n; i += 2, ++tmp)
			cout << i + 1 << " - " << i << " = 1\n";
		while (tmp--)
			cout << "1 * 1 = 1\n";
		cout << "3 * 4 = 12\n12 * 2 = 24\n24 * 1 = 24";
	}
}

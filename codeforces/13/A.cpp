#include <bits/stdc++.h>
using namespace std;

int btob(int nm, int b) {
	int ans = 0;
	while (nm) {
		ans += nm % b;
		nm /= b;
	}
	return ans;
}

int main() {
	int n, sm = 0;
	cin >> n;
	for (int i = 2; i < n; ++i)
		sm += btob(n, i);
	int fct = __gcd(sm, n - 2);
	cout << sm / fct << '/' << (n - 2) / fct;
}

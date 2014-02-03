#include <bits/stdc++.h>
using namespace std;
bool e(int i) {
	return i % 2;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; cin >> a[i++])
		;
	int o = count_if(a, a + n, e);
	cout << (o % 2 ? o : n - o);
}

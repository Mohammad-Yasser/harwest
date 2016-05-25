#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	int one, nn;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) one = i;
		if (tmp == n) nn = i;
	}

	cout << max(max(one - 1, nn - 1), max(n - one, n - nn)) << endl;

}

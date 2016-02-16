#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, smallestOdd = 0;
	cin >> n;
	long long ans = 0;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp & 1 && (tmp < smallestOdd or !smallestOdd)) smallestOdd = tmp;
		ans += tmp;
	}
	if (!(ans&1)) smallestOdd = 0;
	cout << ans - smallestOdd;

	return 0;
}

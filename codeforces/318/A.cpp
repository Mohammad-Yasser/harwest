#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int n, m;
	cin >> n >> m;
	cout << (2 * m - 1 <= n ? 2 * m - 1 : 2 * m - n - n % 2);
}

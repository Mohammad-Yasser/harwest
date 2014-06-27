#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	int n, m;
	cin >> n >> c >> m;
	cout << 30 * (n % 12) + m / 2.0 << ' ' << m * 6.0;
}

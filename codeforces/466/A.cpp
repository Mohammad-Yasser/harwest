#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	cout << min(a * n, min((n / m) * b + (n % m) * a, (1 + n / m) * b));
}

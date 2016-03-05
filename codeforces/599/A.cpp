#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int ans = INT_MAX;
	ans = min(ans, a + b + c);
	ans = min(ans, 2 * a + 2 * b);
	ans = min(ans, 2 * c + 2 * b);
	ans = min(ans, 2 * a + 2 * c);

	cout << ans ;

	return 0;
}

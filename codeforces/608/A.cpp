#include <bits/stdc++.h>

using namespace std;

int ps[1003];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, s;
	cin >> n >> s;
	int ans = -1;
	while (n--) {
		int f, t;
		cin >> f >> t;
		ps[f] = max(ps[f], t);
	}

	++s;

	while (s--)
		ans = max (ans + 1 , ps[s]) ;

	cout << ans ;

	return 0;

}

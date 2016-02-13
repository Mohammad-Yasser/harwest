#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			int x = 0, y = 0;
			for (int d = i; d <= j; ++d) {
				if (s[d] == 'U') ++y;
				if (s[d] == 'D') --y;
				if (s[d] == 'L') --x ;
				if (s[d] == 'R') ++x ;

			}
			ans += !x && !y ;
		}
	cout << ans ;

	return 0;
}

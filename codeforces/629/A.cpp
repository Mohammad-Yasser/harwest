#include <bits/stdc++.h>
using namespace std;

string s[101];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = count(s[i].begin(), s[i].end(), 'C');
		ans += tmp * (tmp - 1) / 2;
		tmp = 0;
		for (int j = 0; j < n; ++j)
			tmp += s[j][i] == 'C';
		ans += tmp * (tmp - 1) / 2;
	}
	cout << ans;

	return 0;
}

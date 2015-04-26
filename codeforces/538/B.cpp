#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	int ind = 0;
	string ans[9];
	fill(ans, ans + 9, string(9, '0'));
	reverse(s.begin(), s.end());
	for (int ind = 0; ind < s.size(); ++ind) {
		for (int i = 0; i < s[ind] - '0'; ++i)
			ans[i][ind] = '1';
	}
	ind = 0;
	cout << 9 - count(ans, ans + 9, string(9, '0')) << endl;
	for (; ind < 9 && ans[ind] != string(9, '0'); ++ind) {
		reverse(ans[ind].begin(), ans[ind].end());
		int i = 0;
		for (; i < ans[ind].size() && ans[ind][i] == '0'; ++i)
			;
		cout << ans[ind].substr(i) << ' ';
	}

}

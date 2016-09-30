#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s >> s;
	s = "w" + s + "w";
	vector<int> ans;
	for (int i = 1; i + 1 < s.size(); ++i) {
		if (s[i] == 'B') {
			if (s[i - 1] == 'B')
				++ans.back();
			else
				ans.push_back(1);
		}
	}
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << '\n';
}

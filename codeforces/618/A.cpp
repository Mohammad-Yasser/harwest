#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> ans;
	while (n--) {
		ans.push_back(1);
		while (ans.size() > 1 && ans.back() == ans[ans.size() - 2]) {
			ans.pop_back();
			++ans.back();
		}
	}
	for (int x : ans)
		cout << x << ' ';

	return 0;
}

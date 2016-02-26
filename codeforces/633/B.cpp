#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> m;
	vector<int> ans;
	int cnt = 0;
	for (int i = 0; i < 1e6; ++i) {
		int tmp = i;
		while (tmp && tmp % 5 == 0)
			++cnt, tmp /= 5;
		if (cnt == m) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int x : ans)
		cout << x << ' ';
}

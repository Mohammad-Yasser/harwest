#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i + b.size() - 1 < a.size(); ++i) {
		int j = 0;
		for (; j < b.size() && a[i + j] == b[j]; ++j)
			;
		if (j == b.size()) {
			a[i + j - 1] = '#';
			++ans;
		}
	}
	cout << ans;
}

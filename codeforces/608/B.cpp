#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int cnt[200005][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= b.size(); ++i) {
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		++cnt[i][b[i - 1] - '0'];
	}

	ll ans = 0;
	for (int i = 0; i < a.size(); ++i)
		ans += cnt[i + b.size() - a.size() + 1][a[i] == '0'] - cnt[i][a[i] == '0'];

	cout << ans;

	return 0;

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int h[N], srtd[N];
unordered_map<int, int> mp;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i], srtd[i] = h[i];

	sort(srtd, srtd + n);

	int ans = 0;
	int cntZeroes = n;
	for (int i = 0; i < n; ++i) {
		++mp[h[i]];
		cntZeroes += !mp[h[i]] - (mp[h[i]] == 1);

		--mp[srtd[i]];
		cntZeroes += !mp[srtd[i]] - (mp[srtd[i]] == -1);

		ans += cntZeroes == n;
	}
	cout << ans;
	return 0;
}

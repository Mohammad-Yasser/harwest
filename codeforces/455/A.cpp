#include <bits/stdc++.h>
using namespace std;

long long memo[100005], cnt[100005];

long long DP(int i) {
	if (memo[i] + 1) return memo[i];
	return memo[i] = max(cnt[i] * i + DP(i + 2), DP(i + 1));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	memo[100004] = 0;

	int n;
	cin >> n;

	int tmp;

	while (n--) {
		cin >> tmp;
		cnt[tmp]++;
	}

	cout << DP(0);

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int memo[N][2];
bool vis[N][2];
int acc[N];
int n;

int dp(int ind, bool curr_turn) {
	if (ind == n) return 0;
	int& ret = memo[ind][curr_turn];
	if (vis[ind][curr_turn]) return ret;
	vis[ind][curr_turn] = true;
	ret = acc[ind] - dp(ind + 1, !curr_turn);
	if (ind + 1 < n)
	  ret = max(ret, dp(ind + 1, curr_turn));
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> acc[i];
	}
	for (int i = 1; i < n; ++i) {
		acc[i] += acc[i - 1];
	}
	cout << dp(1, 1);
}

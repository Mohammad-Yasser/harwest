#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int memo[2003][2003][2];

int n, m;
int mxo, diff;

int dp(int ind, int op, bool tk) {
	if (ind == n - m + 1) return !op && tk;
	if (ind > n - m + 1 or op > 2000 or op < 0) return 0;
	int &ret = memo[ind][op][tk];
	if (ret != -1) return ret;
	ret = dp(ind + 1, op + 1, tk);
	ret = (ret + dp(ind + 1, op - 1, tk)) % MOD;
	if (!tk && op >= mxo)
	  ret = (ret + dp(ind + 1, op - diff, 1)) % MOD;
//	cout << ind << ' ' << op << ' ' << tk << ' ' << ret << endl;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	string s;
	cin >> n >> m >> s;
	for (auto &c : s)
		diff += (c == ')') - (c == '('), mxo = max(mxo, diff);
	cout << dp(0, 0, 0);
	return 0;
}

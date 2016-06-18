#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
short memo[N][N][11][2];

string s, t;
#define isEnd(i,j) (i == (int)s.size() or j == (int)t.size())

short dp(short i, short j, char k, bool b) {
	if (isEnd(i, j)) return !!(k - b) * -1000;
	if (!k) return 0;
	auto &res = memo[i][j][k][b];
	if (res != -1) return res;
	if (b)
		res = dp(i, j, k - 1, 0);
	else
		res = max(dp(i + 1, j, k, 0), dp(i, j + 1, k, 0));
	if (s[i] == t[j]) res = max(res, short(1 + dp(i + 1, j + 1, k, 1)));
	return res;
}

int main() {
	memset(memo, -1, sizeof memo);
	short k;
	cin >> k >> k >> k;
	cin >> s >> t;
	cout << dp(0, 0, k, 0);
}

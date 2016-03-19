#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int memo[6][6];
pair<char, char> op[36];
int n, q;

int dp(char c, char ind) {
	if (ind == n - 1) return 1;
	int &ret = memo[c][ind];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < q; ++i)
		if (c == op[i].second)
		  ret += dp(op[i].first, ind + 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo,-1,sizeof memo);
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		cin >> op[i].first >> op[i].second >> op[i].second;
		op[i].first -= 'a' ;
		op[i].second -= 'a' ;
	}

	cout << dp(0,0) ;

}

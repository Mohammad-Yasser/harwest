#include <bits/stdc++.h> 
using namespace std;

const int N = 5e3 + 1;

int memo[N][N];
int acc[N];
int ht[N];
int n;
int dp(int ind, int lst) {
	if (ind == n - 1) return 0;
	int &ret = memo[ind][lst];
	if (ret != -1) return ret;
	if (acc[ind + 1] - acc[lst] <= ht[ind + 1]) return ret = dp(ind + 1, ind + 1);
	ret = 1 + dp(ind + 1, lst);
	int nxt = lower_bound(acc + ind, acc + n + 1, 2 * acc[ind + 1] - acc[lst]) - acc -  1;
	if (nxt < n) ret = min(ret, nxt - ind - 1 + dp(nxt, ind + 1));
	return ret;
}

int main() {
	memset(memo , -1 , sizeof memo) ;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ht[i];
		acc[i + 1] = acc[i] + ht[i] ;
	}
	cout << dp(0 , 0) << endl;
}


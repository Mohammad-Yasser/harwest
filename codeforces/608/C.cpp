#include <bits/stdc++.h>

using namespace std;

int pos[100005], power[100005], memo[100005];
int lst[1000006]; // To avoid log n of binary search. (Unnecessary optimization)

int cnt = 0 ;
int dp(int ind) {
//	if (cnt++ > 3) return 0 ;
//	cout << ind << endl;

	if (ind < 0) return 0;
	int &ret = memo[ind];
	if (ret != -1) return ret;
	return ret = 1 + dp(lst[max(0, pos[ind] - power[ind] - 1)]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	memset(lst, -1, sizeof lst);


	int mx = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i] >> power[i];
		lst[++pos[i]] = i;
	}

	for (int i = 1; i < 1000006; ++i)
		lst[i] = (lst[i] == -1 ? lst[i - 1] : lst[i]);



	for (int i = 0; i < n; ++i)
		mx = max(mx, dp(i));

	cout << n - mx;

	return 0;

}

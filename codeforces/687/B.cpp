#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> st;
const int K = 1000006;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		st.insert(tmp);
	}
	st.insert(1);

	bool can = true;

	for (int i = 2; i <= k; ++i) {
		int lst = 1;
		for (ll j = i; j <= k; j *= i) {
			if (k % j == 0) {
				lst = j;
			}
		}
		if (lst == 1) continue;
		k /= lst;
		bool cn = false;
		for (ll j = lst; j <= K; j += lst) {
			cn |= st.count(j);
		}
		can &= cn;
	}

	if (can) {
		cout << "Yes";
		return 0;
	}

	cout << "No";

}
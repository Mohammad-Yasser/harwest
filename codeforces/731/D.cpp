#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
const int C = 1000006;
int n, c;
vector<int> words[N];

int cnt[C];

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		words[i].resize(tmp);
		for (int j = 0; j < tmp; ++j)
			cin >> words[i][j];
	}

	for (int i = 0; i + 1 < n; ++i) {
		int pos = 0;
		while (pos < words[i].size() && pos < words[i + 1].size()
		  && words[i][pos] == words[i + 1][pos])
			++pos;
		if (pos == words[i].size()) {
			++cnt[0];
			continue;
		}
		if (pos == words[i + 1].size()) {
			cout << -1;
			return 0;
		}
		int x = words[i][pos];
		int y = words[i + 1][pos];
		if (x < y) {
			++cnt[0];
			--cnt[c - y + 1];
			++cnt[c + 1 - x];
			--cnt[c];
		} else {
			++cnt[c + 1 - x];
			--cnt[c - y + 1];
		}
	}

	int curr_cnt = 0;
	for (int i = 0; i < c; ++i) {
		curr_cnt += cnt[i];
		if (curr_cnt == n - 1) {
			cout << i;
			return 0;
		}
	}

	cout << -1;

}

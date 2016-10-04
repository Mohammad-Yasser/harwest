#include <bits/stdc++.h>
using namespace std;

const int M = 2000;
const int N = 2000;

vector<int> bands[M];

int a_old[N];
int a_new[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a_old[i];
		--a_old[i];
		a_new[i] = a_old[i];
		if (a_old[i] < m) bands[a_old[i]].push_back(i);
	}

	for (int i = 0; i < n; ++i)
		if (a_old[i] >= m) {
			int mn = 0;
			for (int i = 0; i < m; ++i) {
				if (bands[i].size() < bands[mn].size()) mn = i;
			}
			int cnt_mn = 0;
			int cnt_can = 0;
			for (int j = 0; j < m; ++j) {
				cnt_mn += (bands[j].size() == bands[mn].size());
				cnt_can += max(0, (int) bands[j].size() - (int) bands[mn].size() - 1);
			}
			for (int j = i; j < n; ++j) {
				cnt_can += (a_old[j] >= m);
			}
			if (cnt_mn > cnt_can) break;
			bands[mn].push_back(i);
		}

	int mn, mx;
	while (true) {
		mn = 0, mx = 0;
		for (int i = 0; i < m; ++i) {
			if (bands[i].size() > bands[mx].size()) mx = i;
			if (bands[i].size() < bands[mn].size()) mn = i;
		}

		int cnt_mn = 0, cnt_can = 0;
		for (int i = 0; i < m; ++i) {
			cnt_mn += (bands[i].size() == bands[mn].size());
			cnt_can += max(0, (int) bands[i].size() - (int) bands[mn].size() - 1);
		}

		if (cnt_mn > cnt_can) break;

		bands[mn].push_back(bands[mx].back());
		bands[mx].pop_back();
	}

	int changes = 0;

	for (int i = 0; i < m; ++i)
		for (int song : bands[i]) {
			a_new[song] = i;
			changes += (a_old[song] != i);
		}

	for (int i = 0; i < m; ++i) {
		if (bands[i].size() < bands[mn].size()) mn = i;
	}
	cout << bands[mn].size() << ' ' << changes << '\n';

	for (int i = 0; i < n; ++i)
		cout << a_new[i] + 1 << ' ';

}
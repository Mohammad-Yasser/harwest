#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int arr[N], ans[N];

int n, m;

pair<int, int> man[N];

vector<int> red;
bool st;
inline void genRed() {
	bool curr = man[m - 1].first;
	int sz = man[m - 1].second;
	for (int i = m - 2; i >= 0; --i) {
		if (man[i].first != curr && man[i].second > sz) {
			red.push_back(sz);
			sz = man[i].second;
			curr ^= 1;
			continue;
		}
		sz = max(man[i].second, sz);
	}
	st = curr;
	if (sz) red.push_back(sz);
	reverse(red.begin(), red.end());
}

inline void genAns() {
	if (st)
		sort(arr, arr + red[0], greater<int>());
	else
		sort(arr, arr + red[0]);

	for (int i = red[0]; i < n; ++i)
		ans[i] = arr[i];

	int l = 0, r = red[0] - 1;
	int ind = red[0];
	for (int i = 0; i + 1 < red.size(); ++i) {
		if (i & 1)
			for (int j = 0; j < red[i] - red[i + 1]; ++j)
				ans[--ind] = arr[l++];
		else
			for (int j = 0; j < red[i] - red[i + 1]; ++j)
				ans[--ind] = arr[r--];
	}

	if (red.size() & 1)
		while (ind)
			ans[--ind] = arr[r--];
	else
		while (ind)
			ans[--ind] = arr[l++];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < m; ++i)
		cin >> man[i].first >> man[i].second, --man[i].first;

	genRed();
	genAns();

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
}

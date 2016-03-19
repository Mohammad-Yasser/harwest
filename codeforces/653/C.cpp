#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

const int N = 150005;

int arr[N];
int n;
inline bool nice(int st = 0, int ed = n) {
	for (int i = max(0, st); i + 1 < min(n, ed); ++i)
		if (!(i & 1) && arr[i] >= arr[i + 1] or (i & 1) && arr[i] <= arr[i + 1]) return 0;
	return 1;
}

unordered_set<int> prs[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<int> nt;
	for (int i = 0; i + 1 < n; ++i)
		if (!nt.size() or i - 1 > nt.back()) {
			if (!(i & 1) && arr[i] >= arr[i + 1]) nt.push_back(i);
			if ((i & 1) && arr[i] <= arr[i + 1]) nt.push_back(i);
		}

	int ans = 0;

	if (nt.size() > 1) {
		int frst = nt[0], sec = nt.back();
		for (int i = frst; i < min(frst + 2, n); ++i)
			for (int j = sec; j < min(sec + 2, n); ++j) {
				swap(arr[i], arr[j]);
				if (nice()) {
					ans += !prs[min(i, j)].count(max(i, j));
					prs[min(i, j)].insert(max(i, j));
				}
				swap(arr[i], arr[j]);
			}

	} else {
		for (int i = 0; i < n; ++i)
			for (int j = nt[0]; j < min(n, nt[0] + 2); ++j) {
				swap(arr[i], arr[j]);
				if (nice(i - 3, i + 3) && nice(j - 3, j + 3)) {
					ans += !prs[min(i, j)].count(max(i, j));
					prs[min(i, j)].insert(max(i, j));
				}
				swap(arr[i], arr[j]);
			}
	}

	cout << ans;
}

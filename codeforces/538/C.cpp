#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int mx = 0;
	pair<int, int> arr[m];
	for (int i = 0; i < m; ++i)
		cin >> arr[i].first >> arr[i].second, mx = max(mx, arr[i].second);
	bool val = 1;
	for (int i = 0; i < m - 1; ++i) {
		int d = abs(arr[i + 1].second - arr[i].second);
		val &= d <= arr[i + 1].first - arr[i].first;
		int m1 = min(arr[i + 1].second, arr[i].second), m2 = max(arr[i + 1].second, arr[i].second);
		d = arr[i + 1].first - arr[i].first - m2 + m1;
		mx = max(mx, d / 2 + m2);
	}

	if (val)
		cout
		<< max(mx, max(arr[0].second + arr[0].first - 1, arr[m - 1].second + n - arr[m - 1].first));
	else
		cout << "IMPOSSIBLE";
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

pair<int, int> arr[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int mx = 0;
	int ind = 0;
	int l = 0, r = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		l += arr[i].first;
		r += arr[i].second;
	}

	mx = abs(l - r);

	for (int i = 1; i <= n; ++i) {
		if (abs(l + 2 * arr[i].second - 2 * arr[i].first - r) > mx) {
			mx = abs(l + 2 * arr[i].second - 2 * arr[i].first - r);
			ind = i;
		}
	}
	cout << ind;
}

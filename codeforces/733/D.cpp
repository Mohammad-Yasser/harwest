#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

map<pair<int, int>, set<pair<int, int>>> mp;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int mx = 0;
	int i1 = -1, i2 = -1;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int arr[3];
		for (int j = 0; j < 3; ++j) {
			cin >> arr[j];
		}
		sort(arr, arr + 3);
		if (arr[0] > mx) {
			mx = arr[0];
			i1 = i;
		}
		auto &tmp = mp[ { arr[1], arr[2] }];
		tmp.insert( { arr[0], i });
		if (tmp.size() == 3) {
			tmp.erase(tmp.begin());
		}
	}

	for (auto &tmp : mp) {
		if (tmp.second.size() != 2) continue;
		auto x =
		  min(
		    { tmp.first.first, tmp.first.second, tmp.second.begin()->first
		      + tmp.second.rbegin()->first });
		if (x > mx) {
			mx = x;
			i1 = tmp.second.begin()->second;
			i2 = tmp.second.rbegin()->second;
		}
	}


	if (i2 == -1) {
		cout << 1 << '\n' << i1 + 1;
		return 0;
	}
	cout << 2 << '\n' << i1 + 1 << ' ' << i2 + 1;

}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

vector<int> bef;
int after[N];

int n, k;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	cin >> n;
	bef.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> bef[i];
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> after[i];
	}

	vector<pair<int, char>> res;
	for (int i = k - 1; i >= 0; --i) {
		int sum = 0;
		int curr = bef.size() - k + i, prev = curr;
		while (curr >= 0 && sum < after[i]) {
			sum += bef[curr];
			--curr;
		}
//		cout << curr << ' ' << prev << ' ' << sum << ' ' << after[i] << ' ' << i << endl;
		bool can = (prev - curr == 1);
		for (int j = prev; j > curr; --j) {
			can |= (bef[j] != bef[prev]);
		}
		can &= (sum == after[i]);
		if (!can) {
			cout << "NO";
			return 0;
		}
		int mx = 0;
		for (int j = prev; j > curr; --j) {
			mx = max(mx, bef[j]);
		}
//		cout << "Max: " << mx << endl;
		int frst = prev;
		int dir = 1;
		for (int j = prev; j > curr; --j) {
			if (j > curr + 1 && bef[j] == mx && bef[j - 1] != mx) {
				frst = j;
				dir = -1;
				break;
			}
			if (j < prev && bef[j] == mx && bef[j + 1] != mx) {
				frst = j;
				dir = 1;
				break;
			}
		}
//		cout << "F , D " << frst << ' ' << dir << endl;
		if (dir == 1) {
			for (int j = frst; j < prev; ++j) {
				res.push_back( { frst, 'R' });
				bef[frst] += bef[frst + 1];
				bef.erase(bef.begin() + frst + 1);
			}
			for (int j = frst; j > curr + 1; --j) {
				res.push_back( { j, 'L' });
				bef[j] += bef[j - 1];
				bef.erase(bef.begin() + j - 1);
			}
		} else {
			for (int j = frst; j > curr + 1; --j) {
				res.push_back( { j, 'L' });
				bef[j] += bef[j - 1];
				bef.erase(bef.begin() + j - 1);
			}
			for (int j = frst; j < prev; ++j) {
				res.push_back( { curr + 1, 'R' });
				bef[curr + 1] += bef[curr + 2];
				bef.erase(bef.begin() + curr + 2);
			}
		}
//		cout << "Bef: ";
//		for (int x : bef)
//			cout << x << ' ';
//		cout << endl;
	}

	if (bef.size() != k) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (auto x : res)
		cout << x.first + 1 << ' ' << x.second << '\n';

}

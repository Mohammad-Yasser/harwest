#include <bits/stdc++.h>
using namespace std;

#define swp for (auto &x : p) swap(x.first, x.second);

int main() {

	pair<int, int> p[3];
	for (auto &x : p)
		cin >> x.first >> x.second;

	for (int i = 0; i < 2; ++i) {
		bool same = 1;
		for (auto &x : p)
			same &= x.first == p[0].first;
		if (same) {
			cout << 1;
			return 0;
		}
		swp ;
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			auto fr = p[!j], sec = p[2 - (j == 2)];
			if (fr.first == sec.first
			  && (p[j].second <= min(fr.second, sec.second)
			    or p[j].second >= max(fr.second, sec.second))) {
				cout << 2;
				return 0;
			}
		}
		swp;
	}

	cout << 3;

	return 0;
}

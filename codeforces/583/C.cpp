#include <bits/stdc++.h> 
using namespace std;

map<int, int> mp;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n * n; ++i) {
		int tmp;
		cin >> tmp;
		++mp[tmp];
	}

	auto it = mp.rbegin();

	vector<int> ans;
	ans.reserve(n);

	while (it != mp.rend()) {
		while (it->second) {
			--it->second;
			for (auto &x : ans)
				mp[__gcd(it->first, x)] -= 2;
			ans.push_back(it->first);
		}
		++it;
	}

	for (auto &x : ans)
		cout << x << ' ';

}

#include <bits/stdc++.h>
using namespace std;
int Low_Bit(int x) {
	// copied :D
	return (x & -x);
}
int main() {
	int sum, limit;
	cin >> sum >> limit;
	vector<pair<int, int> > vec(limit);
	for (int i = 1; i <= limit; ++i)
		vec[i - 1] = make_pair(Low_Bit(i), i);
	sort(vec.rbegin(), vec.rend());
	vector<int> ans;
	for (int i = 0; i < limit; ++i)
		if (vec[i].first <= sum)
			sum -= vec[i].first, ans.push_back(vec[i].second);
	if (sum)
		cout << -1;
	else {
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << ' ';

	}
}

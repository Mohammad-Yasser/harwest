#include <bits/stdc++.h>
using namespace std;

char dgt;
bool srt(pair<int, char> i, pair<int, char> j) {
	if (abs(i.second - dgt) == abs(j.second - dgt)) {
		if (i.second > j.second)
			return 1;
		else if (j.second > i.second)
			return 0;
		else if (i.first < j.first)
			return i.second > dgt;
		return i.second < dgt;
	}
	return abs(i.second - dgt) < abs(j.second - dgt);
}

int main() {

	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	vector<pair<int, char> > res[10];
	int mncst = 1 << 25;
	vector<string> ans;
	for (int i = 0; i < 10; ++i) {

		for (int j = 0; j < s.size(); ++j)
			res[i].push_back(make_pair(j, s[j]));
		dgt = '0' + i;
		sort(res[i].begin(), res[i].end(), srt);
		int cst = 0;

		for (int j = 0; j < k; ++j)
			cst += abs(res[i][j].second - dgt), res[i][j].second = dgt;
		;

		sort(res[i].begin(), res[i].end());
		string tmp;

		for (int j = 0; j < s.size(); ++j)
			tmp += res[i][j].second;
		if (cst == mncst)
			ans.push_back(tmp);
		else if (cst < mncst) {
			ans.clear();
			ans.push_back(tmp);
			mncst = cst;
		}
	}
	sort(ans.begin(), ans.end());
	cout << mncst << '\n' << ans[0] << endl;

}

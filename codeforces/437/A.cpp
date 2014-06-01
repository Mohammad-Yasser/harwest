#include <bits/stdc++.h>
using namespace std;

bool srt(pair<string, char> s, pair<string, char> y) {
	return s.first.size() < y.first.size();
}

int main() {
	pair<string, char> s[4];
	char c;
	cin >> s[0].second >> c >> s[0].first >> s[1].second >> c >> s[1].first
			>> s[2].second >> c >> s[2].first >> s[3].second >> c >> s[3].first;
	sort(s, s + 4, srt);
	if ((int) s[3].first.size() >= 2 * (int) s[2].first.size()) {
		if (2 * (int) s[0].first.size() <= (int) s[1].first.size()) {
			cout << 'C';
			return 0;
		}
		cout << s[3].second;
		return 0 ;
	}
	if (2 * (int) s[0].first.size() <= (int) s[1].first.size())
		cout << s[0].second;
	else {
		cout << 'C';
		return 0;
	}
}

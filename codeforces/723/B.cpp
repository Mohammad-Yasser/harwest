#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s >> s;
	s += '_';

	bool inside = false;
	int last = 0;
	int words_cnt = 0;
	int longest = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (!isalpha(s[i]) && (i > 0 && isalpha(s[i - 1]))) {
			if (inside) {
				++words_cnt;
			} else {
				longest = max(longest, i - last);

			}
		}
		if (s[i] == '(' || s[i] == ')') {
			inside ^= 1;
		}
		if (!isalpha(s[i])) last = i + 1;
	}

	cout << longest << ' ' << words_cnt;

}

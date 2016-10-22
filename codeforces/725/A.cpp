#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s >> s;
	int res = 0;
	for (int i = 0; i < s.size() && s[i] == '<'; ++i) {
		++res;
	}

	for (int i = s.size() - 1; i >= 0 && s[i] == '>'; --i) {
		++res;
	}

	cout << res;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {

	bool b = 0;
	string s;
	cin >> s;
	if (!count(s.begin(), s.end(), '0')) {
		cout << s.substr(1);
		return 0;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1' or b)
			cout << s[i];
		b |= (s[i] == '0');
	}
}

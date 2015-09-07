#include <bits/stdc++.h>
using namespace std;

#define cin(x,y) for (int i = 0 ; i < (y) ; ++i) cin >> x[i] ;

int n, p;

bool can(string &s, int pos) {
	for (int ind = pos; ind < n; ++ind) {
		char c = (ind == pos ? ++s[pos] : 'a');
		for (; c < 'a' + p; ++c)
			if ((!ind or s[ind - 1] != c) && (ind < 2 or s[ind - 2] != c)) {
				s[ind] = c;
				break;
			}
		if (c == 'a' + p) return 0;
	}
	return 1;
}

int main() {

	cin >> n >> p;
	string s;
	cin >> s;

	for (int i = s.size() - 1; i >= 0; --i) {
		string tmp = s;

		if (can(tmp, i)) {
			cout << tmp;
			return 0;
		}
	}
	cout << "NO";
}

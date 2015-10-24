#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s >> s;

	int l = 1e5, r = 0;

	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'R') {
			l = min(l, i + 1);
			r = max(r, i + (s[i + 1] == '.') + 1);
		}

	if (l == 1e5) {
		swap(l, r);
		for (int i = s.size() - 1; i >= 0; --i)
			if (s[i] == 'L') {
				l = max(l, i + 1);
				r = min(r, i + 1 - (s[i - 1] == '.'));
			}
	}

	cout << l << ' ' << r;

}

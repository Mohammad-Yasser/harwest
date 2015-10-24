#include <bits/stdc++.h> 
using namespace std;

#define sz(v) (int)(v.size())

bool fn(string s1, string s2) {

	bool y = 0;

	for (int i = 0; i < sz(s2); ++i) {
		string a = s1;

		int ind = 0;
		bool cnt = count(s1.begin(), s1.end(), '1') & 1;

		for (int j = i; j < sz(s2); ++j) {
			if (cnt != (s2[j] == '1')) {
				while (ind < sz(a) && a[ind] == '0')
					++ind;
				if (ind == sz(a)) goto r;
				++ind;
				cnt ^= 1;
			}
			a += s2[j];
			cnt ^= (s2[j] == '1');
		}
		y |= a.substr(max(ind, sz(a) - sz(s2))) == s2;
		r: ;
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	bool y = fn(s1, s2);
	if (count(s1.begin(), s1.end(), '1') & 1)
	  y |= fn(s1 + "1", s2);
	cout << (y ? "YES" : "NO");
}

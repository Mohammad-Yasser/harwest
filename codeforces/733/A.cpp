#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string vowels = "AEIOUY";

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	string s;
	cin >> s;
	s = "A" + s + "A";
	int mx = 0;

	for (int i = 0; i + 1 < s.size(); ++i) {
		if (vowels.find(s[i]) != string::npos) {
			int curr = i + 1;
			while (vowels.find(s[curr]) == string::npos)
				++curr;
			mx = max(mx, curr - i);
		}
	}
	cout << mx;

}

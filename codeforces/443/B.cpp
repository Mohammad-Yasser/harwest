#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	for (int i = ((s.size() + n) / 2) * 2; i > 0; i -= 2)
		for (int j = 0; j + i <= (int) s.size() + n; ++j) {
			bool b = 1;
			for (int z = j; z < j + i / 2; ++z)
				if (z + i / 2 < (int) s.size() && s[z] != s[z + i / 2])
					b = 0;
			if (b) {
				cout << i;
				return 0;
			}
		}
	cout << 0;
}

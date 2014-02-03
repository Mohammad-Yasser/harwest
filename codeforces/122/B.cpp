#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int f = count(s.begin(), s.end(), '4'), v = count(s.begin(), s.end(), '7');
	if (!(v or f))
		cout << -1;
	else if (f > v or v == f)
		cout << 4;
	else
		cout << 7;

	return 0;
}

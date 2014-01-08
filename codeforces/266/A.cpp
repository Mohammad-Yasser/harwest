#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() {
	int n;
	cin >> n;
	n = 0;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); ++i)
		if (s[i] == s[i - 1])
			++n;
	cout << n;

	return 0;
}

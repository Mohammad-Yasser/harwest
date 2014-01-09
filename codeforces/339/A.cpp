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
	string s;
	cin >> s;
	s.erase(remove(s.begin(), s.end(), '+'), s.end());
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() - 1; cout << s[i] << '+', ++i)
		;
	cout << s[s.size() - 1];

	return 0;
}

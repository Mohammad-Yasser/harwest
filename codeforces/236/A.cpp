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
	set<char> c;
	char r;
	while (cin >> r)
		c.insert(r);
	cout << ((c.size() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!");

	return 0;
}

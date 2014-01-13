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

	int i = 1, m;
	for (; i <= 25; ++i) {
		cin >> m;
		if (m)
			break;
	}
	cout << abs(i/5+bool(i%5)-3) + abs((i%5)+!(i%5)-3) ;

	return 0;
}

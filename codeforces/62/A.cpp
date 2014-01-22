#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const double eps = 1e-9;
int main() {
	ios_base::sync_with_stdio(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout
			<< ((d >= a - 1 && d <= 2 * a + 2 || c >= b - 1 && c <= 2 * b + 2) ?
					"YES" : "NO");

	return 0;
}

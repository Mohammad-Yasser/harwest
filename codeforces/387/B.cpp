#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int z[a], q[b];

	for (int i = 0; i < a; cin >> z[i++])
		;
	int e = 0;
	for (int i = 0; i < b; cin >> q[i++])
		;
	for (int i = 0; i < a; ++i) {

		for (int ii = 0; ii < b; ++ii)
			if (q[ii] >= z[i]) {
				q[ii] = 0;
				goto r;
			}
		e++;
		r: ;
	}
	cout << e;
}

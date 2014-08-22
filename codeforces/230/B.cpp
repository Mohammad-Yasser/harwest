#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	bool b[1000000];
	fill(b, b + 1000000, 1);
	for (int i = 3; i < 1000; i += 2)
		if (b[i])
			for (int j = i * i; j < 1000000; b[j] = 0, j += i)
				;
	int n;
	cin >> n;
	long long a;

	while (cin >> a) {
		double w = sqrt(a);
		cerr << w;
		if (a == 4)
			goto rr;
		if (a == 1)
			goto r;
		if (w == (int) w && int(w) % 2 && b[(int) w])
			rr: cout << "YES";
		else
			r: cout << "NO";
		cout << endl;
	}

	return 0;
}

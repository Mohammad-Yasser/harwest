#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int N = 200005;

struct BIT {
	vector<int> v;
	BIT(int s) {
		resize(s);
	}
	void clear() {
		v.clear();
	}
	BIT() {
	}
	void resize(int s) {
		s = 1 << (int) ceil(log(1.0 * s) / log(2.) + EPS);
		v.resize(s);
	}
	// get returns count of numbers <= i
	int get(int i) {
		i++;
		int r = 0;
		while (i) {
			r += v[i - 1];
			i -= i & -i;
		}
		return r;
	}
	void add(int i, int val = 1) {
		i++;
		while (i <= (int) v.size()) {
			v[i - 1] += val;
			i += i & -i;
		}
	}
	int find(int val) {
		int s = 0;
		int m = v.size() >> 1;
		while (m) {
			if (v[s + m - 1] < val)
			  val -= v[(s += m) - 1];
			m >>= 1;
		}
		return s;
	}
} bit(N);


int factInd[2][N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	int tmp;


	for (int q = 0; q < 2; ++q) {
		for (int i = 0; i < n; ++i)
			bit.add(i);

		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			factInd[q][i] = bit.get(tmp) - 1;
			bit.add(tmp, -1);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		factInd[0][i] += factInd[1][i];
		if (factInd[0][i] >= n - i) {
			factInd[0][i] -= n - i;
			if (i) ++factInd[0][i - 1];
		}
	}

	for (int i = 0; i < n; ++i)
		bit.add(i);

	for (int i = 0; i < n; ++i) {
		int curr = bit.find(factInd[0][i] + 1);
		cout << curr << ' ';
		bit.add(curr, -1);
	}

	return 0;
}

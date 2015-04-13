#include <bits/stdc++.h>
using namespace std;

int v[2], ts, d;

int dst(int sv, int t, int ev) {
	int nd = (ev - sv) / d + 1;
	return nd * (2 * sv + d * (nd - 1)) / 2 + ev * (t - nd);
}
int main() {
	cin >> v[0] >> v[1] >> ts >> d;
	if (!d) {
		cout << v[0] * ts;
		return 0;
	}
	int ind = (ts * d + v[1] - v[0] + d) / 2 / d,
	  mx1 = min(v[0] + (ind - 1) * d, v[1] + (ts - ind) * d),
	  mx2 = min(v[0] + ind * d, v[1] + (ts - ind - 1) * d);



	cout
	<< max(dst(v[0], ind, mx1) + dst(v[1], ts - ind, mx1),
	  dst(v[0], ind + 1, mx2) + dst(v[1], ts - ind - 1, mx2));

}

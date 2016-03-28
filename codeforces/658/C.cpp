#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 100005;
int q[N];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d, h;
	cin >> n >> d >> h;
	if (2 * h < d or d < h or n > 2 && d == 1) {
		cout << -1;
		return 0;
	}
	int curr = 2;
	for (int i = 0; i <= d; ++i) {
		if (i == h)
			q[i] = 1;
		else
			q[i] = curr++;
		if (i) cout << q[i - 1] << ' ' << q[i] << '\n';
	}
	while (curr != n + 1)
		cout << q[1] << ' ' << curr++ << '\n';

}

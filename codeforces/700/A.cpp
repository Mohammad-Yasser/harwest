#include <bits/stdc++.h> 
using namespace std;

int n;
double l, v1, v2, k;

inline bool can(double x, double l = l) {
	int curr_n = n;
	double dt, y;
	while (curr_n > 0) {
		if (x >= l / v1) return 1;
		if (x < l / v2) return 0;
		y = (x * v1 * v2 - v2 * l) / (v1 - v2);
		dt = y / v2 + (y - y * v1 / v2) / (v1 + v2);
		x -= dt;
		l -= dt * v1;
		curr_n -= k;
	}
	return 1;
}

inline double Bs() {
	long double low = 0, high = l / v1, mid;
	while (abs(low - high) > 1e-9) {
		mid = (low + high) / 2;
		if (can(mid))
			high = mid - 1e-9;
		else
			low = mid + 1e-9;
	}
	return high;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l >> v1 >> v2 >> k;
	cout << fixed << setprecision(9) << Bs();
}

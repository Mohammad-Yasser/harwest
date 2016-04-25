#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 100005, M = 303;
const double EPS = 1e-15;
double mx[N], mn[N];
double p1[N], p2[N];
int n;

inline double solve(double a, double b, double c) {
	return (-b + sqrt(b * b - 4 * a * c + EPS)) / (2 * a);
}

int main() {
	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

	cout << fixed << setprecision(6);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> mx[i];
	for (int i = 0; i < n; ++i)
		cin >> mn[i];

	double sum1 = 0, sum2 = 0;

	for (int i = 0; i < n; ++i) {
		if (!mx[i] && !mn[i])
		  continue;
		double a = 1,
		  b = -mx[i] - sum1 + sum1 * sum2 - mn[i] + sum2 * (1 - sum1),
		  c = mx[i] * (1 - sum2) - mn[i] * sum2;

		p2[i] = solve(a, b, c);
		p1[i] = (mx[i] - p2[i] * sum1) / (p2[i] + sum2);
		sum1 += p1[i];
		sum2 += p2[i];
	}

	for (int i = 0; i < n; ++i)
		cout << p1[i] << " \n"[i + 1 == n];

	for (int i = 0; i < n; ++i)
		cout << p2[i] << " \n"[i + 1 == n];

}

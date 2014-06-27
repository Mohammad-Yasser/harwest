#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int b[2];

long long cnt(long long &i, int r = 0) {
	stringstream ss;
	ss << i;
	string s;
	ss >> s;
	if (count(s.begin(), s.end(), '0') == (int) s.size() - 1
			&& (int) s.size() > 1)
		b[r]++, i += 10;
	return (int) s.size() - 1;
}

bool tt(long long i) {
	stringstream ss;
	ss << i;
	string s;
	ss >> s;
	return *s.begin() == *s.rbegin();
}

long long pw(long long b, long long p) {
	if (!p)
		return 1;
	if (p == 1)
		return b;
	return (p % 2 ? b : 1) * pw(b * b, p / 2);
}

int main() {

	long long x, y, pwx, pwy, tx = 0;
	cin >> x >> y;
	for (; x <= min(y, 103LL); tx += tt(x), ++x)
		;
	x--;
	if (y <= 103) {
		cout << tx;
		return 0;
	}
	pwx = pw(10, cnt(x, 0) - 1), pwy = pw(10, cnt(y, 1) - 1);
	cout
			<< tx + b[0] - b[1] + pwy
					+ (y / pw(10, cnt(y)) - 1) * pw(10, cnt(y) - 1)
					+ (y % ((y / pw(10, cnt(y))) * pw(10, cnt(y))) / 10)
					+ (y % 10 >= y / pw(10, cnt(y)))
					- (pwx + (x / pw(10, cnt(x)) - 1) * pw(10, cnt(x) - 1)
							+ (x % ((x / pw(10, cnt(x))) * pw(10, cnt(x))) / 10)
							+ (x % 10 >= x / pw(10, cnt(x))));

}

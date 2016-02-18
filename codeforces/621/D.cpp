#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld x, y, z;

struct Option {
	ld a, b, c;
	ld lg() {
		return c * log(b * pow(log(a), 1 / c));
	}
	ld pw() {
		return pow(a, pow(b, c));
	}
} options[9];

inline void fill(int &i1) {
	options[i1++] = {x,y,z};
	options[i1++] = {x,z,y};
	options[i1++] = {x , y*z , 1};
}



int main() {
	cin >> x >> y >> z;
	bool allLess = max(x, max(y, z)) < 1;

	int i1 = 0;
	fill(i1);
	swap(x, y);
	fill(i1);
	swap(z, x);
	fill(i1);

	int ans = -1;

	for (int i = 0; i < 9; ++i)
		if (!allLess && options[i].a >= 1 && (ans == -1 or options[i].lg() > options[ans].lg())
		  or allLess && (ans == -1 or options[i].pw() > options[ans].pw())) ans = i;

	if (ans == 0) cout << "x^y^z";
	if (ans == 1) cout << "x^z^y";
	if (ans == 2) cout << "(x^y)^z";

	if (ans == 3) cout << "y^x^z";
	if (ans == 4) cout << "y^z^x";
	if (ans == 5) cout << "(y^x)^z";

	if (ans == 6) cout << "z^x^y";
	if (ans == 7) cout << "z^y^x";
	if (ans == 8) cout << "(z^x)^y";

	return 0;
}

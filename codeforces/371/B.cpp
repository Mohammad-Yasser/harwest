//============================================================================
// Name        : 371B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int n(int b, int a) {
	if (b == a)
		return 0;
	int z = 0;
	while (b / a % 5 == 0 && b / 5 >= a) {
		b /= 5, z++;
		if (b == a)
			return z;
	}

	while (b / a % 3 == 0 && b / 3 >= a) {
		b /= 3, z++;
		if (b == a)
			return z;
	}
	while (b / a % 2 == 0 && b / 2 >= a) {
		b /= 2, z++;
		if (b == a)
			return z;
	}
	if (b != a)
		return -1;
	return z;
}
int main() {
	int a, b;
	cin >> a >> b;
	int gcd = __gcd(a, b);
	int n1 = n(a, gcd), n2 = n(b, gcd);
	cerr << n1 << " " << n2 << endl;

	if (n1 != -1 && n2 != -1)
		cout << n1 + n2 << endl;
	else
		puts("-1");
}

#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		a |= tmp;
	}

	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		b |= tmp;
	}
	cout << a+b;

}

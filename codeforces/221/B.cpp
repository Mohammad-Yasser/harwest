#include <bits/stdc++.h>
using namespace std;

string its(int s) {
	stringstream ss;
	string i;
	ss << s;
	ss >> i;
	return i;
}

int main() {

	int nm = 0, x;
	cin >> x;
	string xs = its(x);
	for (int i = 1; i <= sqrt(x); ++i)
		if (x % i == 0) {
			string s = its(i), s2 = its(x / i);
			nm += (xs.find_first_of(s) != string::npos)
					+ (xs.find_first_of(s2) != string::npos && i * i != x);

		}
	cout << nm;
}

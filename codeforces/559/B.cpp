#include <bits/stdc++.h>
using namespace std;

string canon(string &a) {
	if (a.size() % 2)
	  return a;

	string a1 = a.substr(0, a.size() / 2), a2 = a.substr(a.size() / 2);
	a1 = canon(a1), a2 = canon(a2);
	if (a1 > a2) swap(a1, a2);
	return a1 + a2;

}

int main() {

	string a, b;
	cin >> a >> b;

	cout << (canon(a) == canon(b) ? "YES" : "NO");

	return 0;
}

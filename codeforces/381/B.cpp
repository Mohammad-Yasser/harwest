#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int main() {

	int n, b;
	cin >> n;
	vector<int> t;
	t.resize(n);
	for (int i = 0; i < n; cin >> t[i], ++i)
		;
	sort(t.begin(), t.end());
	int mx = 0;
	for (int i = n - 1; i >= 0; --i) {
		mx = max(t[i], mx);

	}
	vector<int> y;
	for (int i = 0; i < t.size(); ++i) {

		if (t[i] < mx && find(y.begin(), y.end(), t[i]) == y.end()) {


			y.push_back(t[i]);
			t.erase(t.begin() + i);
			--i;
		}
	}
	y.push_back(mx);

	vector<int> z;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] < mx && find(z.begin(), z.end(), t[i]) == z.end()) {
			z.push_back(t[i]);
			t.erase(t.begin() + i);
			--i ;
		}
	}
	cout << y.size() + z.size() << endl;
	sort(y.begin(),y.end()) ;
	for (int i = 0; i < y.size(); cout << y[i] << " ", ++i)
		;
	sort(z.rbegin(),z.rend()) ;
	for (int i = 0; i < z.size(); cout << z[i] << " ", ++i)
		;

}

//My Name is Ibrahim.

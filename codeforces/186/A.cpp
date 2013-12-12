#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

int main() {
	string a, b;
	ui t;
	bool q = 1;
	cin >> a >> b;
	if (a.size() != b.size()) {
		cout << "NO";
		return 0;
	} else

		for (ui i = 0; i < a.size(); i++) {
			if (a[i] != b[i] && q) {
				t = i;
				q = 0;
			} else if (a[i] != b[i]) {
				swap (a[i],a[t]) ;
				if (a==b)
					cout << "YES";
				else
					cout << "NO";
				return 0;
			}
		}
	cout << "NO";
}

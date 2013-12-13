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

int main() {
	int k;
	cin >> k;
	string s[4];
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for (int i = 0; i < 4; i++)
		for (int q = 0; q < 4; q++) {
			if (s[i][q] != '.') {
				if (count(s[0].begin(), s[0].end(), s[i][q])
						+ count(s[1].begin(), s[1].end(), s[i][q])
						+ count(s[2].begin(), s[2].end(), s[i][q])
						+ count(s[3].begin(), s[3].end(), s[i][q]) > 2*k) {
					cout << "NO";
					return 0;
				};
			}
		}
	cout << "YES";
	return 0;
}

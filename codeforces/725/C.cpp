#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string grid[2];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	grid[0].resize(13);
	grid[1].resize(13);

	int first, second;
	for (int i = 0; i < s.size(); ++i)
		if (s.find(s[i]) < i) {
			first = s.find(s[i]);
			second = i;
		}

	if (second == first + 1) {
		cout << "Impossible";
		return 0;
	}

	int ind = first, x = 0, y = (second - first - 1) / 2;
	int dir = -1;
	while (ind < second) {
		grid[x][y] = s[ind];
		++ind;
		y += dir;
		if (y < 0) y = 0, x = 1, dir = 1;
	}

	++ind;

	while (ind < s.size()) {
		grid[x][y] = s[ind];
		++ind;
		y += dir;
		if (y == 13) y = 12, x = 0, dir = -1;
	}

	ind = 0;
	while (ind < first) {
		grid[x][y] = s[ind];
		++ind;
		y += dir;
		if (y == 13) y = 12, x = 0, dir = -1;
	}

	cout << grid[0] << '\n' << grid[1];

	return 0;
}

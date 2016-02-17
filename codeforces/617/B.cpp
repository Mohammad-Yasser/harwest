#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool firstOne = 0;
	long long ways = 1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		bool tmp;
		cin >> tmp;
		if (!tmp && firstOne) ++cnt;
		if (tmp && firstOne) ways *= ++cnt, cnt = 0;
		if (tmp && !firstOne) firstOne = 1;
	}

	if (!firstOne) ways = 0;
	cout << ways;

	return 0;
}

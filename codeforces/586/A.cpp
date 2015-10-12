#include <bits/stdc++.h> 
using namespace std;

int main() {

	int n;
	cin >> n;
	bool arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int start = 0, _end = n - 1;
	while (start < n && !arr[start])
		++start;

	while (_end >= 0 && !arr[_end])
		--_end;

	int cnt = 0;
	bool here = 1;
	for (int i = start; i <= _end; ++i) {
		if (!arr[i] && i + 1 < n && !arr[i + 1]) here = 0;
		if (arr[i]) here = 1;
		cnt += here;
	}

	cout << cnt;

}

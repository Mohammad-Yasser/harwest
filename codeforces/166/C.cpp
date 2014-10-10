#include <bits/stdc++.h>
using namespace std;

bool arr[5003];

int main() {

	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	if (arr[(n + 1) / 2 - 1] < m)
		cout << max(2 * (lower_bound(arr, arr + n, m) - arr) - n + 1, 0);
	else
		cout << max(2 * (arr - upper_bound(arr, arr + n, m)) + n, 0);
}

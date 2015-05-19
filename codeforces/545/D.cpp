#include <bits/stdc++.h>
using namespace std;

int main() {
	// I doubt this solution can work for a D problem. :D
	// But this contest isn't rated for me, so why would I be so serious :v

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	long long sum = 0;
	for (int idx = 0; idx < n; ++idx)
		if (arr[idx] >= sum) sum += arr[idx], ++ans;
	cout << ans;

}

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m, ans = 0;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; cin >> arr[i++])
		;
	while (cin >> n >> m)
		ans += min(arr[n - 1], arr[m - 1]);
	cout << ans;

}

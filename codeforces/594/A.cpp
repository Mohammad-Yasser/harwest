#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int mn = INT_MAX;

	for (int i = 0; i + n / 2 < n; ++i)
		mn = min(mn, arr[i + n / 2] - arr[i]);

	cout << mn;

}

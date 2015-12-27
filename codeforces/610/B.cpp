#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int mn = *min_element(arr, arr + n);

	int first = -1, last, ans = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] <= mn) {
			if (first == -1) first = i;
			ans = max(ans, i - last - 1);
			last = i;
		}

	ans = max(ans, first + n - 1 - last);
	cout << 1LL * mn * n + ans;

}

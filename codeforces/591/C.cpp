#include <bits/stdc++.h> 
using namespace std;

#define sz(v) (int)(v.size())

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int arr[500005];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	arr[n] = arr[n - 1];

	bool prev = arr[0];
	int length = 1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (arr[i] == prev) {
			for (int j = i - length; j < i; ++j)
				arr[j] = ((i - j <= length >> 1) ^ !prev) & ~length & 1 | length & 1 & prev;

			ans = max(ans, (length + 1) / 2 - 1);
			length = 0;
		}
		prev = arr[i];
		++length;
	}

	cout << ans << endl;
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

}

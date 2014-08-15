#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	long long n;
	cin >> n;
	long long arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[n - 1] - arr[0] << ' '
			<< (arr[n - 1] == arr[0] ?
					n * (n - 1) / 2 :
					(long long) (count(arr, arr + n, arr[n - 1]))
							* (long long) (count(arr, arr + n, arr[0])));

}

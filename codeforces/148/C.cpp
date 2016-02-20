#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main() {

	int n, a, b;
	cin >> n >> a >> b;
	if (!b && a) {
		if (a > n - 2)
			cout << -1;
		else {
			cout << "2 1 3 ";
			int curr = 3;
			for (int i = 3; i < a + 2; ++i)
				cout << ++curr << ' ';
			for (int i = a + 2 ; i < n ; ++i)
				cout << "1 " ;
		}
		return 0;
	}
	int sum = 1;
	arr[0] = 1;

	for (int i = 1; i <= b; ++i)
		arr[i] = sum + 1, sum += arr[i];
	for (int i = b + 1; i <= b + a; ++i)
		arr[i] = arr[i - 1] + 1;
	for (int i = b + a + 1; i < n; ++i)
		arr[i] = 1;

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	return 0;
}

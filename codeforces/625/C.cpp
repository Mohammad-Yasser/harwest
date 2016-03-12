#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501;

int arr[N][N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	--k;
	int sum = 0, curr = n * n;
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j >= k; --j)
			arr[i][j] = curr--;
		sum += arr[i][k];
	}
	cout << sum << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = k - 1; j >= 0; --j)
			arr[i][j] = curr--;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cout << arr[i][j] << " \n"[j + 1 == n];
}

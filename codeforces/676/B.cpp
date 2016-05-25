#include <bits/stdc++.h> 
using namespace std;

const int N = 11;

int arr[N][N];

const int SH = 1 << 9 ;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int t;
	cin >> t;

	t *= SH;

	arr[0][0] = t;
	int ans = 0 ;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			if (arr[i][j] >= SH) {
				int tmp = (arr[i][j] - SH) / 2;
				arr[i + 1][j] += tmp;
				arr[i + 1][j + 1] += tmp;
				++ans ;
			}
	cout << ans ;
}

#include <bits/stdc++.h>
using namespace std;

#define cin(x,y) for (int i = 0 ; i < (y) ; ++i) cin >> x[i] ;

int main() {

	int n;
	cin >> n;
	bool arr[n];

	cin(arr, n);

	int ans = 0;

	bool single = 0;

	for (int i = 0; i < n; ++i)
		ans += (arr[i] ^ single) | (arr[i] & single), single = arr[i];

	cout << ans - !arr[n - 1] + !ans;

}

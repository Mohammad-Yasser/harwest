#include<bits/stdc++.h>
using namespace std;
int s[1000006];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, k;

	cin >> n >> k ;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int b2 = 2 * max(n - k, 0);

	int ans = 0 ;

	for (int i = 0 ; 2 * i < b2 ; ++i)
		ans = max(ans , s[i] + s[b2 - 1 - i]) ;

	for (int i = b2 ; i < n ; ++i)
		ans = max(ans , s[i]) ;

	cout << ans ;

	return 0;
}

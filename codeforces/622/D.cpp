#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int n;
	cin >> n;

	for (int i = 1; i <= n; i += 2)
		cout << i << ' ';
	for (int i = n - 2 + !(n & 1); i >= 1; i -= 2)
		cout << i << ' ';

	for (int i = 2; i <= n; i += 2)
		cout << i << ' ';
	for (int i = n - 1 - !(n & 1); i >= 1; i -= 2)
		cout << i << ' ';

	cout << n;

}
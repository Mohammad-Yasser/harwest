#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int arr[26];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	ll ans = 0;
	int curr = 1e9 + 3;
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; ++i)
		arr[i] = min(arr[i], curr - 1), ans += max(0,arr[i]), curr = arr[i];
	cout << ans;

}

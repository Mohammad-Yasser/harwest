#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

const int N = 200005;
int arr[N];
int first[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	first[n - 1] = n;
	for (int i = n - 2; i >= 0; --i) {
		if (arr[i + 1] == arr[i]) {
			first[i] = first[i + 1];
		} else {
			first[i] = i + 1;
		}
	}

	while (m--) {
		int l , r , x;
		cin >> l >> r >> x;
		--l,--r;
		if (arr[l] == x) {
			if (first[l] > r) {
				cout << "-1\n";
			} else {
				cout << first[l] + 1 << '\n';
			}
		} else {
			cout << l + 1 << '\n';
		}
	}

}

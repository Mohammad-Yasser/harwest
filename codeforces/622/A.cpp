#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int get(ll n) {
	int curr = 1;
	while (n > curr) {
		n -= curr++;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	ll n;

	cin >> n;
	cout << get(n);

}

#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int d, l, v1, v2;
	cin >> d >> l >> v1 >> v2;
	cout << fixed << setprecision(7) << 1.0 * (l - d) / (v1 + v2);
}

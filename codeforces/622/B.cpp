#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int main() {
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int hrs, mins, a;
	char c;
	cin >> hrs >> c >> mins >> a;
	mins += hrs * 60 + a;
	mins %= 24 * 60;

	printf("%02d:%02d", mins / 60, mins % 60);

}

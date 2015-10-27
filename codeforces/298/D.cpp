#include <bits/stdc++.h> 
using namespace std;

#define sz(v) (int)(v.size())

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k, tmp;
	cin >> n >> m >> k;

	map<int, int> cnt;

	while (n--) {
		cin >> tmp;
		++cnt[tmp];
	}

	while (m--) {
		cin >> tmp;
		--cnt[tmp];
	}

	tmp = 0;
	bool yes = 0 ;

	for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
		tmp += it->second ;
		yes |= tmp > 0 ;
	}

	cout << (yes ? "YES" : "NO") ;
}

#include <bits/stdc++.h> 
using namespace std;

int cnt[1000027];

int main() {

	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;


	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		++cnt[tmp];
	}

	for (int i = 0; i < 1000025; ++i) {
		cnt[i + 1] += cnt[i] >> 1;
		cnt[i] &= 1;
	}


	cout << accumulate(cnt, cnt + 1000025, 0);

}

#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int cnt[10];

int main() {
	cnt[0] = 6, cnt[1] = 2, cnt[2] = 5, cnt[3] = 5, cnt[4] = 4, cnt[5] = 5;
	cnt[6] = 6, cnt[7] = 3, cnt[8] = 7, cnt[9] = 6;

	int a, b;
	cin >> a >> b;
	int ans = 0;
	string s;
	while (a <= b) {
		int tmp = a++;
		while (tmp)
			ans += cnt[tmp % 10], tmp /= 10;
	}
	cout << ans ;

	return 0;
}

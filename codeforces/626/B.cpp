#include <bits/stdc++.h>
using namespace std;

int memo[202][202][202];


// I think there's a much simpler solution, but I'm already late.
int dp(int r, int g, int b) {
	int &ret = memo[r][g][b];
	if (ret != -1) return ret;
	ret = 0;
	if (r + g + b == 1) {
		if (r) return 1;
		if (g) return 2;
		if (b) return 4;
	}
	if (r > 1) ret |= dp(r - 1, g, b);
	if (g > 1) ret |= dp(r, g - 1, b);
	if (b > 1) ret |= dp(r, g, b - 1);
	if (r  && b )
	  ret |= dp(r - 1, g + 1, b - 1);
	if (r && g )
	  ret |= dp(r - 1, g - 1, b + 1);
	if (g && b )
	  ret |= dp(r + 1, g - 1, b - 1);
	return ret;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	int b = 0, g = 0, r = 0;
	for (char x : s)
		b += x == 'B', g += x == 'G', r += x == 'R';
	memset(memo, -1, sizeof memo);
	int ans = dp(r, g, b);
	if (ans & 4) cout << 'B';
	if (ans & 2) cout << 'G';
	if (ans & 1) cout << 'R';

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

char memo[N][2][2];

int lst;
string s;
string ansL, ansR;

bool sh ;

char dp(int ind, bool c1, bool c2) {
	if (ind > lst - ind) return c1 == c2;
	char &ret = memo[ind][c1][c2];
	if (ret != -1) return ret;
	ret = 0;

	if (ind == lst - ind) {
		for (int i = !(ind - sh); i < 10; ++i)
			if (!ret) {
				char c = 2 * i + c2;
				ret = (s[ind] == c % 10 && c1 == c / 10);
				if (ret) ansL += i + '0';
			}
	}
	else
		for (int i = !(ind - sh); i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				for (char b = 0; b < 2; ++b)
					if (!ret) {
						char l = i + j + b, r = i + j + c2;
						if (s[ind] == l % 10 && c1 == l / 10 && s[lst - ind] == r % 10)
						  ret = dp(ind + 1, b, r / 10);
						if (ret) {
							ansL += i + '0';
							ansR += j + '0';
						}
					}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	cin >> s;
	lst = s.size() - 1;
	for (auto &x : s)
		x -= '0';

	if (dp(0, 0, 0)) {
		reverse(ansL.begin(), ansL.end());
		cout << ansL + ansR;
		return 0;
	}
	ansL = ansR = "";
	if (s[0] == 1) {
		sh = 1;
		++lst ;
		memset(memo, -1, sizeof memo);
		if (dp(1, 1, 0)) {
			reverse(ansL.begin(), ansL.end());
			cout << ansL + ansR;
			return 0;
		}

	}
	cout << 0;

}

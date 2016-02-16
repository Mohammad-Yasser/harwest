#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i,m) for(int i=0;i<m;i++)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> > vll;
const int MOD = 1e9 + 7;
struct Mat {
	vll m;
	int r, c;
	Mat() {
	}
	Mat(int r1, int c1) {
		r = r1;
		c = c1;
		m = vll(r, vl(c, 0));
	}
	Mat idn(int r1) {
		Mat res(r1, r1);
		rep(i,r1)
					res.m[i][i] = 1;
		return res;
	}
	Mat operator *(Mat &a) const {
		Mat res(r, a.c);
		rep(i,r)
					rep(j,a.c)
							rep(k,c)
									res.m[i][j] = (res.m[i][j] + m[i][k] * a.m[k][j]) % MOD;
		return res;
	}
	Mat operator ^(ll b) {
		if (b == 0)
		  return idn(r);
		Mat t = (*this) ^ b / 2;
		Mat tt = t * t;
		if (b % 2 == 0)
		  return tt;
		return tt * (*this);
	}
};
int cnt[10];

int main() {
	int n, b, k, x;
	cin >> n >> b >> k >> x;
	--b;
	while (n--) {
		int tmp;
		cin >> tmp;
		++cnt[tmp];
	}
	Mat adj(max(10, x), max(10, x));
	for (int i = 0; i < max(10, x); ++i)
		for (int j = 1; j <= 9; ++j)
			adj.m[i][(i * 10 + j) % x] += cnt[j];
	adj = adj ^ b;

	ll ans = 0;
	for (int i = 1; i <= 9; ++i)
		ans = (ans + cnt[i] * adj.m[i][k]) % MOD;


	cout << ans;

	return 0;
}

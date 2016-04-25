#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 101;

int n, m, q;

int arr[N][N];

vector<pair<int, int> > shifts;

inline void set_(int r, int c, int x) {
	for (int i = shifts.size() - 1; i >= 0; --i) {
		if (shifts[i].first == 1 && shifts[i].second == r)
		  if (++c == m + 1) c = 1;
		if (shifts[i].first == 2 && shifts[i].second == c)
		  if (++r == n + 1) r =  1;
	}
	arr[r - 1][c - 1] = x;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &q);

	while (q--) {
		int t, x;
		scanf("%d", &t);
		if (t == 1 or t == 2) {
			scanf("%d", &x);
			shifts.push_back( { t, x });
		}
		else {
			int r, c;
			scanf("%d %d %d", &r, &c, &x);
			set_(r, c, x);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j) putchar(' ') ;
			printf("%d" , arr[i][j]) ;
		}
		puts("") ;
	}

}

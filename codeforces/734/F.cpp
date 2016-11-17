#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
int a[N];
int b[N];
int c[N];

ll sum_bc;
ll sum_a;

int cnt[32];

int main() {
//	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
		sum_bc += b[i] + c[i];
	}

	sum_a = sum_bc / (2 * n);

	for (int i = 0; i < n; ++i) {
		a[i] = (c[i] + b[i] - sum_a) / n;
		if (a[i] < 0) {
			puts("-1");
			return 0;
		}
		for (int j = 0; j < 32; ++j) {
			cnt[j] += (a[i] >> j) & 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		ll res_b = 0;
		for (int j = 0; j < 32; ++j) {
			if ((a[i] >> j) & 1) {
				res_b += (1 << j) * cnt[j];
			}
		}
		if (res_b != b[i]) {
			puts("-1");
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ",a[i]);
	}

	return 0;
}

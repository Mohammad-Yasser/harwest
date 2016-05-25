#include <bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 3;

int b[N];
int cntB;
int a[N];
int cntA;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i)
		if (s[i] == 'a')
			a[cntA++] = i;
		else
			b[cntB++] = i;

	for (int i = cntA; i < N; ++i)
		a[i] = n;

	for (int i = cntB; i < N; ++i)
		b[i] = n;

	cntA = cntB = 0;

	int ans = 0;


	for (int i = 0; i < n; ++i) {
		ans = max(ans, a[cntA + k] - i);
		ans = max(ans, b[cntB + k] - i);

		cntA += (s[i] == 'a');
		cntB += (s[i] == 'b');
	}

	cout << ans << endl;

}

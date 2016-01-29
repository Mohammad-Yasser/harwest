#include <bits/stdc++.h>
using namespace std;

bool fnd[51];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	bool fndN = 0;
	for (int i = 0; i < n; ++i) {
		memset(fnd, 0 , sizeof fnd);
		bool curr = 0;
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;
			if (fnd[tmp] && !curr) cout << tmp << ' ', curr = 1;
			fnd[tmp] = 1;
		}
		if (!curr) cout << n - fndN << ' ', fndN = 1;
	}

	return 0;
}

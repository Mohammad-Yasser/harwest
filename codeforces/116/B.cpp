#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, pigs = 0, wolves = 0;
	cin >> n >> m;
	char mp[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; cin >> mp[i][j], ++j)
			;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'P'
					&& (i > 0 && mp[i - 1][j] == 'W'
							or i < n - 1 && mp[i + 1][j] == 'W'
							or j > 0 && mp[i][j - 1] == 'W'
							or j < m - 1 && mp[i][j + 1] == 'W'))
				pigs++;
			if (mp[i][j] == 'W'
					&& (i > 0 && mp[i - 1][j] == 'P'
							or i < n - 1 && mp[i + 1][j] == 'P'
							or j > 0 && mp[i][j - 1] == 'P'
							or j < m - 1 && mp[i][j + 1] == 'P'))
				wolves++;
		}
	cout << min(wolves,pigs) ;

}

#include<bits/stdc++.h>
using namespace std;

bool impass[1003][1003];
int vis[1003][1003], cnt[1003][1003];
int n, m;

int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
	if (x == n or y == m or vis[x][y] or impass[x][y]) return 0;

	vis[x][y] = 1;

	for (int i = 0; i < 4; ++i)
		cnt[x][y] += impass[x + dx[i]][y + dy[i]] + dfs(x + dx[i], y + dy[i]);

	return cnt[x][y];
}

void dfs2(int x, int y, int val) {
	if (x == n or y == m or vis[x][y] or impass[x][y]) return;
	vis[x][y] = 1;
	cnt[x][y] = val;
	for (int i = 0; i < 4; ++i)
		dfs2(x + dx[i], y + dy[i], val);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			impass[i][j] = (c == '*');
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dfs(i, j);

	memset(vis, 0, sizeof vis);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dfs2(i, j,cnt[i][j]);

	while (k--) {
		int i,j;
		cin >> i >> j ;
		cout << cnt[i][j] << '\n' ;

	}

	return 0;
}

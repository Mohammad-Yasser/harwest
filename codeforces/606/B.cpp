#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n, m;
bool valid(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

int dx[129], dy[129];

bool vis[505][505];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	dx['U'] = dy['L'] = -1;
	dx['D'] = dy['R'] = 1;
	int x, y;
	cin >> n >> m >> x >> y;

	cout << "1 ";
	vis[x][y] = 1;

	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 0; i + 1 < s.size(); ++i) {
		if (valid(x + dx[s[i]], y + dy[s[i]]))
		  x += dx[s[i]], y += dy[s[i]];
		if (vis[x][y])
			cout << "0 ";
		else
			cout << "1 ", vis[x][y] = 1, ++cnt;
	}

	cout << n * m - cnt;
}

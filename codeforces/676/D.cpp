#include <bits/stdc++.h> 
using namespace std;

struct State {
	unsigned int x, y;
	unsigned int rotation :2;
};

const int N = 1003;
string grid[N];
bool vis[N][N][4];

int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };

int n, m;

inline bool hasDoor(char c, int i) {
	if (c == '+') return 1;
	if (c == '-') return i < 2;
	if (c == '|') return i > 1;
	if (c == '^') return i == 2;
	if (c == 'v') return i == 3;
	if (c == '>') return i == 0;
	if (c == '<') return i == 1;
	if (c == 'L') return i != 1;
	if (c == 'R') return i != 0;
	if (c == 'U') return i != 2;
	if (c == 'D') return i != 3;
	return 0;
}

inline char convert(char c, int rot) {
//	cout << c << ' ' << rot << endl;
	if (!rot) return c;
	if (c == '+')
		c = '+';
	else if (c == '-')
		c = '|';
	else if (c == '|')
		c = '-';
	else if (c == '^')
		c = '>';
	else if (c == 'v')
		c = '<';
	else if (c == '>')
		c = 'v';
	else if (c == '<')
		c = '^';
	else if (c == 'L')
		c = 'U';
	else if (c == 'R')
		c = 'D';
	else if (c == 'U')
		c = 'R';
	else if (c == 'D')
		c = 'L';
	else if (c == '*') c = '*';
	return convert(c, rot - 1);
}

inline bool valid(State curr, int i) {
	int x = curr.x + dx[i], y = curr.y + dy[i];
	if (x < 0 or y < 0 or x >= n or y >= m) return 0;
	return hasDoor(convert(grid[x][y], curr.rotation), i ^ 1)
	  && hasDoor(convert(grid[curr.x][curr.y], curr.rotation), i);
}

int main() {
//	cout << convert('<',1) ;
//	return 0 ;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	int xm, ym, xr, yr;
	cin >> xr >> yr >> xm >> ym;
	--xr, --yr, --xm, --ym;
	queue<State> q;
	q.push( { xr, yr, 0 });
	int lvl = 0;
	while (q.size()) {
		int sz = q.size();

		while (sz--) {
			auto curr = q.front();
			q.pop();
			if (curr.x == xm && curr.y == ym) {
				cout << lvl;
				return 0;
			}

			for (int i = 0; i < 4; ++i) {
				int x = curr.x + dx[i];
				int y = curr.y + dy[i];
				if (valid(curr, i) && !vis[x][y][curr.rotation])
				  vis[x][y][curr.rotation] = 1, q.push( { x, y, curr.rotation });
			}

			if (!vis[curr.x][curr.y][++curr.rotation])
			  vis[curr.x][curr.y][curr.rotation] = 1, q.push( { curr.x, curr.y, curr.rotation });

		}

		++lvl;
	}
	cout << -1;
}

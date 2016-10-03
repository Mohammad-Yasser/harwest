#include <bits/stdc++.h>
using namespace std;

// Most probably I misunderstand the problem, because for my understanding,
// its solution is O(n * m * log(n * m)), which is too little for a D problem, and the solution is too simple.

const int N = 53;

int grid[N][N];
int curr_id;
int n, m, k;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int cnt;

void fill(int x, int y) {
	if (x > n || y > m || x == -1 || y == -1) return;
	if (grid[x][y] == curr_id) return;
	if (grid[x][y] == -1) return;

	grid[x][y] = curr_id;
	++cnt;
	for (int i = 0; i < 4; ++i)
		fill(x + dx[i], y + dy[i]);
}

bool is_transformed[3003];

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	n += 2, m += 2;

	for (int i = 1; i + 1 < n; ++i)
		for (int j = 1; j + 1 < m; ++j) {
			char c;
			cin >> c;
			if (c == '*')
			  grid[i][j] = -1;
		}

	vector<pair<int, int> > components;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 0) {
				++curr_id;
				cnt = 0;
				fill(i, j);
				if (curr_id != 1)
				  components.push_back( { cnt, curr_id });
			}
		}

	sort(components.begin(), components.end());
	int ans = 0;

	for (int i = 0; i + k < components.size(); ++i) {
		is_transformed[components[i].second] = true;
		ans += components[i].first;
	}

	cout << ans << '\n';
	for (int i = 1; i + 1 < n; ++i)
		for (int j = 1; j + 1 < m; ++j) {
			if (grid[i][j] > 0 && is_transformed[grid[i][j]]) grid[i][j] = -1;
			if (grid[i][j] == -1)
				cout << '*';
			else
				cout << '.';
			if (j + 2 == m) cout << '\n';
		}

}

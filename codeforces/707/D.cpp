#include <bits/stdc++.h> 
using namespace std;

const int N = 1e3;

bool grid[N][N];
bool inverted[N];
int shelf[N];
int total;

const int Q = 1e5 + 1;

vector<int> children[Q];

struct Query {
	int type, i, j;
	int ans;
} queries[Q];

int n, m, q;

void dfs(int u) {
	for (int v : children[u]) {
		auto& q = queries[v];
		if (q.type < 3 && q.type) {
			bool changed = grid[q.i][q.j] ^ inverted[q.i] ^ (q.type == 1);

			if (changed) {
				shelf[q.i] += (q.type == 1) - (q.type == 2);
				total += (q.type == 1) - (q.type == 2);
				grid[q.i][q.j] ^= 1;
			}
			q.ans = total;
			dfs(v);

			if (changed) {
				shelf[q.i] -= (q.type == 1) - (q.type == 2);
				total -= (q.type == 1) - (q.type == 2);
				grid[q.i][q.j] ^= 1;
			}
			continue;
		}
		if (q.type == 3) {
			inverted[q.i] ^= 1;
			total += m - 2 * shelf[q.i];
			shelf[q.i] = m - shelf[q.i];
			q.ans = total;

			dfs(v);

			inverted[q.i] ^= 1;
			total += m - 2 * shelf[q.i];
			shelf[q.i] = m - shelf[q.i];
			continue;
		}

		q.ans = total;
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;

	for (int i = 1; i <= q; ++i) {
		cin >> queries[i].type >> queries[i].i;
		if (queries[i].type <= 2) cin >> queries[i].j;
		if (queries[i].type == 4)
			children[queries[i].i].push_back(i);
		else
			children[i - 1].push_back(i), --queries[i].i, --queries[i].j;
	}

	dfs(0);

	for (int i = 1; i <= q; ++i)
		cout << queries[i].ans << '\n';

}

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];

int col[N];

bool dfs(int node, int cl) {
	if (col[node] != 0 && col[node] != cl) return false;
	if (col[node] == cl) return true;
	col[node] = cl;

	for (int v : adj[node]) {
		if (!dfs(v, cl ^ 3)) {
			return false;
		}
	}
	return true;
}

int n;
bool solve() {
	for (int i = 1; i <= n; ++i) {
		if (col[i] == 0 && !dfs(i, 1)) {
			return false;
		}
	}
	return true;
}

vector<int> cover[2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (!solve()) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cover[col[i] - 1].push_back(i);
	}
	for (int i = 0; i < 2; ++i) {
		cout << cover[i].size() << '\n';
		for (int node : cover[i]) {
			cout << node << ' ';
		}
		cout << '\n';
	}
}

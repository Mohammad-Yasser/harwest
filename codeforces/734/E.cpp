#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;

int n;
bool color[N];

vector<int> adj[N];
vector<int> adj_new[N];
int comp[N];

void SetComp(int u, int id) {
	if (comp[u]) return;
	comp[u] = id;

	for (int v : adj[u]) {
		if (color[v] == color[u]) {
			SetComp(v, id);
		} else {
			adj_new[id].push_back(v);
		}
	}
}

bool vis[N];

pair<int, int> bfs(int u) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(u);
	vis[u] = true;

	int level = 0, last = u;

	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int curr = q.front();
			q.pop();
			last = curr;
			for (int v : adj_new[curr]) {
				if (vis[v]) continue;
				vis[v] = true;
				q.push(v);
			}
		}
		++level;
	}

	return {last , level};
}

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> color[i];
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		SetComp(i, i);
	}

	for (auto &adj : adj_new)
		for (auto &v : adj) {
			v = comp[v];
		}

//	for (int i = 1; i <= n; ++i) {
//		cout << i << ": ";
//		for (int v : adj_new[i]) {
//			cout << v << ' ';
//		}
//		cout << endl;
//	}

	int diameter = bfs(bfs(1).first).second;
	cout << diameter / 2;

	return 0;
}


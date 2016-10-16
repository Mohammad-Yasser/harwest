#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int n, k;
int cnt[N];
int color[N];
int res;
bool vis[N];
vector<int> adj[N];

void Solve(int u) {
	vector<int> comp;
	queue<int> q;
	q.push(u);
	vis[u] = true;
	int mx = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		comp.push_back(curr);
		++cnt[color[curr]];
		mx = max(mx, cnt[color[curr]]);
		for (int v : adj[curr])
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
	}
	res += comp.size() - mx;
	for (int x : comp)
		cnt[color[x]] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int m;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> color[i];
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			Solve(i);
		}
	cout << res;

}

#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

const int N = 500005;
vector<int> adj[N];
int n;

multiset<int> leaves;

void dfs(int u, int par, int dist) {
	if (adj[u].size() == 1) {
		leaves.insert(dist);
	}
	for (int v : adj[u])
		if (v != par) dfs(v, u, dist + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int mx = 0;
	for (int v : adj[1]) {
		leaves.clear();
		dfs(v, 1, 0);
		int curr = -1;
		for (int d : leaves) {
			curr = max(curr + 1, d);
		}
		mx = max(mx, curr);
	}
	cout << ++mx << '\n';

}

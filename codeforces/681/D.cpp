#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool root[N], wanted[N];
int par[N], depth[N], a[N];
bool valid = 1;
vector<int> children[N];

void setDepth(int node, int d = 0) {
	depth[node] = d;
	for (int v : children[node])
		setDepth(v, d + 1);
}

int check(int node) {
	int mn = a[node];
	for (int v : children[node])
		mn = min(mn, check(v));
	valid &= (!wanted[node] or mn >= depth[node]);
	return mn;
}

int main() {
	memset(root, 1, sizeof root);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		par[v] = u;
		root[v] = 0;
		children[u].push_back(v);
	}

	for (int i = 0; i < n; ++i)
		if (root[i]) setDepth(i);

	vector<pair<int, int> > ans;

	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i], wanted[a[i]] = 1;
		ans.push_back( { depth[a[i]], a[i] + 1 });
		a[i] = depth[a[i]];
	}

	for (int i = 0; i < n; ++i)
		if (root[i]) check(i);

	sort(ans.rbegin(), ans.rend());

	if (!valid) {
		cout << -1;
		return 0;
	}

	vector <int> res ;


	for (int i = 0; i < n; ++i)
		if (!i or ans[i - 1].second != ans[i].second)
			res.push_back(ans[i].second) ;
	cout << res.size() << '\n' ;
	for (int x : res) cout << x << '\n' ;

}

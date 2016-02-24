#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int root = 0;
int parent[N];
vector<int> children[N];
const int levels = log2(N) + 3;
int p[N][levels];
int lvl[N];
int n;

void buildP(int node = root) {
	p[node][0] = parent[node];
	for (int i = 1; i < levels && p[node][i - 1] != -1; ++i)
		p[node][i] = p[p[node][i - 1]][i - 1];

	for (int v : children[node])
		if (v != parent[node]) {
			lvl[v] = lvl[node] + 1;
			parent[v] = node;
			buildP(v);
		}
}

int getChildOnPath(int u, int anc) {
	for (int i = levels - 1; i >= 0; --i)
		if (lvl[p[u][i]] > lvl[anc])
		  u = p[u][i];
	return u;
}

inline int getLCA(int u, int v) {
	for (int i = levels - 1; i >= 0; --i)
		if (p[u][i] != -1 && lvl[p[u][i]] >= lvl[v])
		  u = p[u][i];
	for (int i = levels - 1; i >= 0; --i)
		if (p[u][i] != p[v][i])
		  u = p[u][i], v = p[v][i];
	if (u != v) u = parent[u];
	return u;
}

int getDistAnc(int u, int v) {
	int ans = 0;
	for (int i = levels - 1; i >= 0; --i)
		if (p[u][i] != -1 && lvl[p[u][i]] >= lvl[v])
		  ans += 1 << i, u = p[u][i];
	return ans;
}

int getDist(int u, int v, int lca = -1) {
	if (lca == -1) lca = getLCA(u, v);
	return getDistAnc(u, lca) + getDistAnc(v, lca);
}

int sz[N];

int getSize(int node) {
	if (sz[node]) return sz[node];
	int &res = sz[node];
	res = 1;
	for (int &v : children[node])
		if (v != parent[node])
		  res += getSize(v);
	return res;
}

ll sumDist[N];

ll getSumDist(int node) {
	ll &ret = sumDist[node];
	if (ret != -1) return ret;
	ret = 0;
	for (int &v : children[node])
		if (v != parent[node])
		  ret += getSumDist(v) + getSize(v);
	return ret;
}

unordered_map<int, ll> sumDistUp[N];
ll getSumDistUp(int node, int child) {
	if (node == -1) return 0;
	if (sumDistUp[node].count(child))
	  return sumDistUp[node][child];
	return sumDistUp[node][child] = getSumDist(node) - getSumDist(child) - getSize(child) + n
	  - getSize(node) + getSumDistUp(parent[node], node);
}

void init() {
	memset(p, -1, sizeof p);
	memset(sz, 0, sizeof sz);
	memset(sumDist, -1, sizeof sumDist);
	lvl[root] = 0;
	parent[root] = -1;
}

long double calc(ll size1, ll size2, ll sm1, ll sm2, ll dist) {
	return size1 * size2 * (1 + dist) + size1 * sm2 + size2 * sm1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


	init();
	int m;
	cin >> n >> m;
	cout << fixed << setprecision(7);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		children[u].push_back(v);
		children[v].push_back(u);
	}
	buildP();
	while (m--) {
		long double ans = 0;
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (lvl[u] < lvl[v]) swap(u, v);
		int lca = getLCA(u, v);
		int childOnPath = getChildOnPath(u, lca);
		int dist = getDist(u, v, lca);
		if (lca == v) {
			ll sz1 = n - getSize(childOnPath), sz2 = getSize(u);
			ans = calc(sz1, sz2, getSumDistUp(v, childOnPath), getSumDist(u), dist) / (sz1 * sz2);
		}
		else {
			ll sz1 = getSize(u), sz2 = getSize(v);
			ans = calc(sz1, sz2, getSumDist(u), getSumDist(v), dist) / (sz1 * sz2);
		}

		cout << ans << '\n';
	}
}

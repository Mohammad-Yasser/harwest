#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 1e5 + 1, SZ = 2 * (1 << ((int) (log2(N)) + 1));
const int INF = 1e9;
struct SegmentTree {
	ll tree[SZ];

	void buildTree() {
		memset(tree, 0, sizeof tree);
	}

	void set(int node, int a, int b, int i, ll val) {
		if (a > b or a > i or b < i) return;
		if (a == b) {
			tree[node] = val;
			return;
		}
		set(node * 2, a, (a + b) / 2, i, val);
		set(node * 2 + 1, (a + b) / 2 + 1, b, i, val);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}

	ll query(int node, int a, int b, int i, int j) {

		if (a > b or a > j or b < i) return 0;
		if (a >= i && b <= j) return tree[node];

		return max(query(node * 2, a, (a + b) / 2, i, j),
		  query(node * 2 + 1, (a + b) / 2 + 1, b, i, j));
	}

} tree;

ll vol[N];
map<ll, int> mp;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		ll r, h;
		cin >> r >> h;
		vol[i] = r * r * h;
		mp[vol[i]];
	}

	int tmpInd = 0;

	for (auto &x : mp)
		x.second = tmpInd++;

	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int srtInd = mp[vol[i]];
		ll tmp = tree.query(1, 0, n - 1, srtInd + 1, n - 1) + vol[i];
		ans = max(ans, tmp);
		tree.set(1, 0, n - 1, srtInd, tmp);
	}

	cout << fixed << setprecision(7) << ans * acos(-1);

}

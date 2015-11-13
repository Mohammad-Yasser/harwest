#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 262145;

struct SegmentTree {
	struct node {
		int from, to;
		ll sum;
	} nodes[SIZE];

	ll val[100005];

	void createTree(int node = 1, int from = 1, int to = 100005) {
		nodes[node] = {from,to,0};
		if (from == to) return;
		createTree(2 * node , from , (from + to) / 2);
		createTree(2 * node + 1, (from + to) / 2 + 1 , to);
	}

	ll query(int from , int to=100005,int node =1) {

		if (nodes[node].from > to or nodes[node].to < from) return 0;
		if (nodes[node].from >= from && nodes[node].to <= to) return nodes[node].sum;
		return query(from , to,2 * node ) + query(from , to,2 * node + 1);
	}

	void update(int index,ll diff,int node = 1) {
		if (index < nodes[node].from or index > nodes[node].to) return;
		if (nodes[node].from == nodes[node].to) {
			nodes[node].sum += diff;
			val[index] += diff;
			return;
		}
		update (index, diff , 2 * node);
		update (index, diff , 2 * node + 1);
		nodes[node].sum = nodes[2 * node].sum + nodes[2 * node + 1].sum;
//		cout << nodes[node].from << ' ' << nodes[node].to << ' ' << nodes[node].sum << endl;
	}
};

SegmentTree acc[13];

int arr[100005];

int main() {
	ios::sync_with_stdio(false);

	for (int i = 0; i < 13; ++i)
		acc[i].createTree();

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	ll ans = 0;

	for (int i = n - 1; i >= 0; --i) {
		acc[1].update(arr[i], 1);
		for (int j = 2; j < 13; ++j) {
			ll tmp = acc[j - 1].query(arr[i] + 1);
			acc[j].update(arr[i], tmp);
		}
		ans += acc[k + 1].val[arr[i]];

	}
	cout << ans;

	return 0;
}

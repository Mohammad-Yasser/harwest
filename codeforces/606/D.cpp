#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int weight, ind;
	bool included;
};

bool cmpW(const Edge& a, const Edge&b) {
	return a.weight < b.weight or a.weight == b.weight && a.included > b.included;
}

Edge edges[100005];

pair<int, int> ans[100005];

int lastCycle[100005], currCycle, lstNode;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		lastCycle[i] = i + 1;

	for (int i = 0; i < m; ++i)
		cin >> edges[i].weight >> edges[i].included, edges[i].ind = i;

	sort(edges, edges + m, cmpW);

	for (int i = 0; i < m; ++i)
		if (edges[i].included)
			ans[edges[i].ind] = {lstNode,lstNode+1}, currCycle = 0,++lstNode;
			else {

				if (currCycle + 1 >= lstNode) {
					cout << -1;
					return 0;
				}
				ans[edges[i].ind] = {currCycle,++lastCycle[currCycle]};
				currCycle += (lastCycle[currCycle] == lstNode);
			}

	for (int i = 0; i < m; ++i)
		cout << ++ans[i].first << ' ' << ++ans[i].second << '\n';

}

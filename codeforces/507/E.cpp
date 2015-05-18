#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100005][2];

struct Element {
	Element(int d, int w, int p, int c) :
		distance(d), workingRoads(w), parent(p), curr(c) {
	}
	int distance, workingRoads, parent, curr;
	bool operator <(Element other) const {
		if (distance == other.distance) return workingRoads < other.workingRoads;
		return distance > other.distance;
	}
};
int parent[100005];
int main() {
	int n, m;
	cin >> n >> m;
	int x, y, z, cntWorking = 0;
	while (m--) {
		cin >> x >> y >> z;
		edges[x][0].push_back(y), edges[y][0].push_back(x);
		edges[x][1].push_back(z), edges[y][1].push_back(z);
		cntWorking += z;
	}

	priority_queue<Element> Q;

	Element element(0, 0, -1, 1);
	Q.push(element);

	while (1) {
		element = Q.top();
		Q.pop();

		if (parent[element.curr] > 0) continue;
		parent[element.curr] = element.parent;

		if (element.curr == n) break;

		for (int i = 0; i < edges[element.curr][0].size(); ++i) {
			Element tmp(element.distance + 1, element.workingRoads + edges[element.curr][1][i],
			  element.curr, edges[element.curr][0][i]);
			if (!parent[tmp.curr]) Q.push(tmp);
		}
	}

	int curr = element.curr;
	set<pair<int, int> > st;
	while (curr != 1)
		st.insert(make_pair(min(curr, parent[curr]), max(curr, parent[curr]))), curr = parent[curr];

	cout << cntWorking + st.size() - 2 * element.workingRoads << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < edges[i][0].size(); ++j) {
			if (edges[i][0][j] < i && (st.count(make_pair(edges[i][0][j], i)) ^ edges[i][1][j]))
			  cout << i << ' ' << edges[i][0][j] << ' ' << !edges[i][1][j] << '\n';
		}

}

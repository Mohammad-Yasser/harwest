#include <bits/stdc++.h>
using namespace std;

//struct Edge {
//	int u, v, idx;
//	long long w;
//	Edge(int u, int v, long long w, int i) :
//		u(u), v(v), w(w), idx(i) {
//	}
//	Edge() {
//	}
//	bool operator <(Edge other) const {
//		return w < other.w;
//	}
//};
//
//Edge edges[300005];

int weight[300005];

struct adjListElem {
	int v, w, idx;
	adjListElem(int v, int w, int idx) :
		v(v), w(w), idx(idx) {
	}
};
vector<adjListElem> adjList[300005];

struct PQElem {
	int v;
	long long w;
	int lastEdge;
	PQElem(int v, long long w, int lastEdge) :
		v(v), w(w), lastEdge(lastEdge) {
		this->w = w;
	}
	bool operator <(PQElem other) const {
		if (w == other.w) return weight[lastEdge] > weight[other.lastEdge];
		return w > other.w;
	}
};

int lastEdge[300005];

void dijkstra(int u) {
	priority_queue<PQElem> Q;
	Q.push(PQElem(u, 0, -1));

	while (!Q.empty()) {

		PQElem curr = Q.top();
		Q.pop();

		if (lastEdge[curr.v]) continue;
		lastEdge[curr.v] = curr.lastEdge;

		for (int i = 0; i < adjList[curr.v].size(); ++i)
			if (!lastEdge[adjList[curr.v][i].v])
			  Q.push(
			    PQElem(adjList[curr.v][i].v, curr.w + adjList[curr.v][i].w, adjList[curr.v][i].idx));
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		adjList[ui].push_back(adjListElem(vi, wi, i));
		adjList[vi].push_back(adjListElem(ui, wi, i));
		weight[i] = wi;
	}

	int u;
	cin >> u;
	dijkstra(u);

	long long ans = 0;

	for (int i = 1; i <= n; ++i)
		if (i != u)
		  ans += weight[lastEdge[i]];

	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
		if (i != u) cout << lastEdge[i] << ' ';
}

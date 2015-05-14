#include <bits/stdc++.h>
using namespace std;

int dist[3003][3003];

vector<int> edges[3003];

void BFS(int start) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(start, 0));
	while (!Q.empty()) {
		pair<int, int> curr = Q.front();
		Q.pop();
		for (int i = 0; i < edges[curr.first].size(); ++i)
			if (dist[start][edges[curr.first][i]] == 1e7) {
				dist[start][edges[curr.first][i]] = curr.second + 1;
				Q.push(make_pair(edges[curr.first][i], curr.second + 1));
			}
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 3003; ++i)
		for (int j = 0; j < 3003; ++j)
			dist[i][j] = (i != j) * 1e7;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edges[a].push_back(b), edges[b].push_back(a);
	}

	int s1, s2, t1, t2, l1, l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

	for (int i = 1; i <= n; ++i)
		BFS(i);


	if (dist[s1][t1] > l1 or dist[s2][t2] > l2) {
		cout << -1;
		return 0;
	}

	int ans = dist[s1][t1] + dist[s2][t2];

	for (int i = 1; i <= n; ++i) // First intersection point
		for (int j = 1; j <= n; ++j)  // Last intersection point
			for (int k = 0; k < 2; ++k) {
				swap(s1, t1);
				if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1
				  && dist[s2][i] + dist[i][j] + dist[j][t2] <= l2)
				  ans = min(ans, dist[s1][i] + dist[i][j] + dist[j][t1] + dist[s2][i] + dist[j][t2]);
			}

	cout << m - ans;

}

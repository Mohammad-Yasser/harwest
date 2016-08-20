#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const ll OO = 1e15;
const int N = 1e5 + 1;
ll dist[N];

vector<pair<int, int> > adj[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	fill(dist, dist + N, OO);

	while (m--) {
		int u, v, l;
		cin >> u >> v >> l;
		--u, --v;
		adj[u].push_back( { v, l });
		adj[v].push_back( { u, l });
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> > > q;
	ll ans = OO;

	while (k--) {
		int x;
		cin >> x;
		--x;
		q.push( { 0, x });
	}

	while (!q.empty()) {
		auto curr = q.top();
		q.pop();
		if (dist[curr.second] <= curr.first) continue;
		dist[curr.second] = curr.first;
		if (curr.first) ans = min(ans, curr.first);

		for (auto v : adj[curr.second])
			q.push( { curr.first + v.second, v.first });
	}

	if (ans == OO)
		cout << -1;
	else
		cout << ans;

}

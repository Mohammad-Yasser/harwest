#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

const int N = 505;
char s[N];

int n, m;

inline bool neighbouring(char a, char b) {
	return abs(a - b) < 2;
}

bool adj[N][N];

bool bt(int u, int v) {
	if (v == n) return 1;
	if (!s[v]) {
		for (char j = 'a'; j < 'd'; j += 2)
			if (neighbouring(s[u], j) == adj[u][v]) {
				s[v] = j;
				if (bt(v, 0) && bt(u, v + 1))
				  return 1;
				s[v] = 0;
			}
		return 0;
	}
	return neighbouring(s[u], s[v]) == adj[u][v] && bt(u, v + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		adj[i][i] = 1;

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u][v] = adj[v][u] = 1;
	}

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (!adj[i][j])
			  for (int k = j + 1; k < n; ++k)
				  if (!adj[i][k] && !adj[j][k]) {
					  cout << "No";
					  return 0;
				  }

	memset(s, 0, sizeof s);

	for (int i = 0; i < n; ++i) {
		bool all = 1;
		for (int j = 0; j < n; ++j)
			all &= adj[i][j];
		if (all) s[i] = 'b';
	}

	for (char j = 0; j < 3; ++j) {
		s[0] = j + 'a';
		if (bt(0, 0)) {
			cout << "Yes\n" << s;
			return 0;
		}
	}
	cout << "No";

}

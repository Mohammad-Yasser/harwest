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

	int nonB = -1;

	for (int i = 0; i < n; ++i) {
		bool all = 1;
		for (int j = 0; j < n; ++j)
			all &= adj[i][j];
		if (all)
			s[i] = 'b';
		else
			nonB = i;
	}

	if (nonB != -1) {
		for (int i = 0; i < n; ++i)
			if (!s[i])
			  s[i] = 'a' + 2 * !adj[nonB][i];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (neighbouring(s[i], s[j]) != adj[i][j]) {
					cout << "No";
					return 0;
				}
	}
	cout << "Yes\n" << s;

}

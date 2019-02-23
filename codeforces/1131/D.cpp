#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2004;

struct DSU {
  vector<int> par;
  int numSet;
  DSU(int n) {
    ++n;
    par.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i;
    numSet = n;
  }

  int find(int node) {
    return par[node] = (par[node] == node) ? node : find(par[node]);
  }

  int find(int ind , bool first) {
    return find(getNodeId(ind , first));
  }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    numSet--;
    par[y] = x;
    return true;
  }

  int getNodeId(int ind, bool first) {
    return ind + first * (N / 2);
  }

} dsu(N);

vector<int> adj[N];
int ingoing[N];
int val[N];
int n, m;

void bfs() {
  queue<int> q;
  for (int i = 0; i < N; ++i) {
    if (ingoing[i] == 0) {
      q.push(i);
      val[i] = 1;
    }
  }

  int level = 2;

  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      int curr = q.front();
      q.pop();

      for (int v : adj[curr]) {
        if (--ingoing[v] == 0) {
          q.push(v);
          val[v] = level;
        }
      }
    }
    ++level;
  }
}

char grid[N / 2][N / 2];

void addEdge(int u, int v) {
  adj[u].push_back(v);
  ++ingoing[v];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '=') {
        dsu.join(dsu.getNodeId(i, true), dsu.getNodeId(j, false));
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x = dsu.find(dsu.getNodeId(i, true));
      int y = dsu.find(dsu.getNodeId(j, false));

      if (grid[i][j] == '<') {
        addEdge(x, y);
      }
      if (grid[i][j] == '>') {
        addEdge(y, x);
      }
    }
  }

  bfs();

  for (int i = 1; i <= n; ++i) {
    if (val[dsu.find(i, true)] == 0) {
      cout << "No";
      return 0;
    }
  }

  for (int i = 1; i <= m; ++i) {
    if (val[dsu.find(i, false)] == 0) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes" << endl;

  for (int i = 1; i <= n; ++i) {
    cout << val[dsu.find(i, true)] << " ";
  }
  cout << endl;

  for (int i = 1; i <= m; ++i) {
    cout << val[dsu.find(i, false)] << " ";
  }
}

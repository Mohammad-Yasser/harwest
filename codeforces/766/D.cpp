#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

unordered_map<string, int> compress;

struct DSU {
  int parent[N];

  DSU() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }

  int GetRoot(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = GetRoot(parent[x]);
  }

  int GetOpp(int x) {
    return x ^ 1;
  }

  int GetNode(int x) {
    return 2 * x;
  }

  void Join(int x, int y) {
    x = GetRoot(x);
    y = GetRoot(y);

    if (x == y) return;

    parent[x] = y;
    Join(GetOpp(x), GetOpp(y));
  }

  bool AreSame(int x, int y) {
    return GetRoot(x) == GetRoot(y);
  }

  bool AreOpp(int x, int y) {
    return AreSame(x, GetOpp(y));
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    compress[s] = i + 1;
  }

  DSU dsu;

  while (m--) {
    int t;
    string a, b;
    cin >> t >> a >> b;
    int x = dsu.GetNode(compress[a]);
    int y = dsu.GetNode(compress[b]);

    if (t == 1) {
      if (dsu.AreOpp(x, y)) {
        cout << "NO\n";
        continue;
      }
      dsu.Join(x, y);
    } else {
      if (dsu.AreSame(x, y)) {
        cout << "NO\n";
        continue;
      }
      dsu.Join(x, dsu.GetOpp(y));
    }

    cout << "YES\n";
  }

  while (q--) {
    string a, b;
    cin >> a >> b;
    int x = dsu.GetNode(compress[a]);
    int y = dsu.GetNode(compress[b]);

    if (dsu.AreSame(x, y)) {
      cout << "1\n";
    } else if (dsu.AreOpp(x, y)) {
      cout << "2\n";
    } else {
      cout << "3\n";
    }
  }

}

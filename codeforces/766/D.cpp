#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;

unordered_map<string, int> compress;

struct DSU {
  int parent[N];
  int opposite[N];

  DSU() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
      opposite[i] = -1;
    }
  }

  int GetRoot(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = GetRoot(parent[x]);
  }

  int GetOpp(int x) {
    return opposite[GetRoot(x)];
  }

  void SetOpp(int x, int opp) {
    opposite[GetRoot(x)] = opp;
  }

  void Join(int x, int y) {
    x = GetRoot(x);
    y = GetRoot(y);

    parent[x] = y;

    if (opposite[y] == -1) {
      opposite[y] = opposite[x];
    }
  }

  bool AreSame(int x, int y) {
    if (x == -1 || y == -1) return false;
    return GetRoot(x) == GetRoot(y);
  }

  bool AreOpp(int x, int y) {
    return AreSame(x, GetOpp(y)) || AreSame(y, GetOpp(x));
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
    int x = compress[a];
    int y = compress[b];

    int opp_x = dsu.GetOpp(x);
    int opp_y = dsu.GetOpp(y);

    if (t == 1) {
      if (dsu.AreSame(x, opp_y) || dsu.AreSame(opp_x, y)) {
        cout << "NO\n";
        continue;
      }
      dsu.Join(x, y);
      if (opp_x != -1 && opp_y != -1) {
        dsu.Join(opp_x, opp_y);
      }
    } else {
      if (dsu.AreSame(x, y) || dsu.AreSame(opp_x, opp_y)) {
        cout << "NO\n";
        continue;
      }

      if (opp_x != -1) {
        dsu.Join(opp_x, y);
      }

      if (opp_y != -1) {
        dsu.Join(x, opp_y);
      }

      dsu.SetOpp(x, y);
      dsu.SetOpp(y, x);
    }

    cout << "YES\n";
  }

  while (q--) {
    string a, b;
    cin >> a >> b;
    int x = compress[a];
    int y = compress[b];

    if (dsu.AreSame(x, y)) {
      cout << "1\n";
    } else if (dsu.AreOpp(x, y)) {
      cout << "2\n";
    } else {
      cout << "3\n";
    }
  }

}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;

pair<int, int> seg[N];

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

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    numSet--;
    par[y] = x;
    return true;
  }
};

vector<pair<int, int>> edges;

int to[N] , from[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  DSU dsu(n + 1);

  for (int i = 1; i <= n; ++i) {
    seg[i] = make_pair(i, i);
  }

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x = dsu.find(x), y = dsu.find(y);


    to[seg[x].second] = seg[y].first;
    from[seg[y].first] = seg[x].second;

    edges.emplace_back(seg[x].second , seg[y].first);

    pair<int, int> p = make_pair(seg[x].first, seg[y].second);
    dsu.join(x, y);
    seg[dsu.find(x)] = p;

  }

  int first = -1;
  for (int i = 1 ; i <= n ; ++i) {
    if (from[i] == 0) {
      first = i;
    }
  }

  for (int i = 1 ; i <= n ; ++i) {
    cout << first << " ";
    first = to[first];
  }


}

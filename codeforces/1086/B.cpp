#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;
double s;

vector<int> adj[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> s;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cnt_leaves = 0;

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) {
      ++cnt_leaves;
    }
  }

  cout << fixed << setprecision(10) << 2 * s / cnt_leaves;

}

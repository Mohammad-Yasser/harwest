#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;

vector<int> adj[N];

Long s[N];
Long a[N];

bool check(int node, Long sum) {
  if (s[node] != -1) {
    a[node] = s[node] - sum;
    sum = s[node];
  } else {
    Long mn = INT_MAX;
    for (int v : adj[node]) {
      mn = min(mn, s[v]);
    }
    if (mn == INT_MAX) {
      mn = sum;
    }
    a[node] = mn - sum;
    sum = mn;
  }

  if (a[node] < 0) return false;

  for (int v : adj[node]) {
    if (!check(v, sum)) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }

  if (!check(1, 0)) {
    cout << -1;
    return 0;
  }

  Long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += a[i];
  }
  cout << res;

}

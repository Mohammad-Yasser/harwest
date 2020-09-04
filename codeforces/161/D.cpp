#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 5e4 + 5;
const int K = 501;
vector<int> adj[N];

Long res;
int k;

vector<int> dfs(int node, int parent) {
  vector<int> cnt(K);
  cnt[0] = 1;
  for (int v : adj[node]) {
    if (parent == v) continue;
    auto child_cnt = dfs(v, node);
    for (int i = 0; i < k; ++i) {
      res += 1LL * cnt[i] * child_cnt[k - i - 1];
    }
    for (int i = 1; i < K; ++i) {
      cnt[i] += child_cnt[i - 1];
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  dfs(1, -1);
  cout << res << endl;

  return 0;
}
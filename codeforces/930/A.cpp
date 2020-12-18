#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 1e5 + 5;

bool seconds[N];

vector<int> children[N];
void dfs(int node, int depth) {
  seconds[depth] ^= 1;
  for (int v : children[node]) {
    dfs(v, depth + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    children[p].emplace_back(i);
  }
  dfs(1, 0);
  cout << accumulate(all(seconds), 0) << endl;

  return 0;
}
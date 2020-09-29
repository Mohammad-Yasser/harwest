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

const int N = 3e5 + 5;

vector<int> occ[N];
int ans[N];
void init(int n) {
  fill(occ, occ + n + 1, vector<int>{0});
  fill(ans, ans + n + 1, N);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      occ[x].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
      occ[i].emplace_back(n + 1);
      int k = 0;
      for (int j = 0; j + 1 < sz(occ[i]); ++j) {
        k = max(k, occ[i][j + 1] - occ[i][j]);
      }
      ans[k] = min(ans[k], i);
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = min(ans[i], ans[i - 1]);
      cout << (ans[i] == N ? -1 : ans[i]) << " ";
    }
    cout << endl;
  }

  return 0;
}
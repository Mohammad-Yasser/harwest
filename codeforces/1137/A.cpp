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

const int N = 1003;
vector<pair<int, int>> rows[N], cols[N];
int cnt[N][N][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      rows[i].emplace_back(x, j);
      cols[j].emplace_back(x, i);
    }
  }

  for (int i = 0; i < n; ++i) {
    sort(all(rows[i]));
    for (int s = 0; s < 2; ++s) {
      int last = 0;
      int cnt_distinct = 0;
      for (int k = 0; k < m; ++k) {
        auto& p = rows[i][k];
        while (rows[i][last].first != p.first) {
          if (last == 0 || rows[i][last].first != rows[i][last - 1].first) {
            ++cnt_distinct;
          }
          ++last;
        }
        cnt[i][p.second][s] = max(cnt[i][p.second][s], cnt_distinct);
      }
      reverse(all(rows[i]));
    }
  }

  for (int j = 0; j < m; ++j) {
    sort(all(cols[j]));
    for (int s = 0; s < 2; ++s) {
      int last = 0;
      int cnt_distinct = 0;
      for (int k = 0; k < n; ++k) {
        auto& p = cols[j][k];
        while (cols[j][last].first != p.first) {
          if (last == 0 || cols[j][last].first != cols[j][last - 1].first) {
            ++cnt_distinct;
          }
          ++last;
        }
        cnt[p.second][j][s] = max(cnt[p.second][j][s], cnt_distinct);
      }
      reverse(all(cols[j]));
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << cnt[i][j][0] + cnt[i][j][1] + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
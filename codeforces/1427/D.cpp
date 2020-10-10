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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  v.emplace(begin(v), 0);
  vector<vector<int>> res;
  while (!is_sorted(all(v))) {
    int x = 0;
    for (int i = 1; i <= n; ++i) {
      if (v[i] > i) {
        x = i;
        break;
      }
    }
    int y = 0;
    for (int i = x; i <= n; ++i) {
      if (v[i] == v[x] - 1) {
        y = i;
        break;
      }
    }
    vector<vector<int>> groups;
    groups.emplace_back(vector<int>(begin(v) + 1, begin(v) + x));
    int x2 = x + 1;
    while (v[x2] > v[x2 - 1]) ++x2;
    groups.emplace_back(vector<int>(begin(v) + x, begin(v) + x2));
    groups.emplace_back(vector<int>(begin(v) + x2, begin(v) + y + 1));
    groups.emplace_back(vector<int>(begin(v) + y + 1, end(v)));
    res.emplace_back(vector<int>());
    for (auto& g : groups) {
      if (!g.empty()) {
        res.back().emplace_back(sz(g));
      }
    }
    reverse(all(groups));
    v.clear();
    v.emplace_back(0);
    for (auto& g : groups) {
      v.insert(end(v), all(g));
    }
  }
  cout << sz(res) << endl;
  for (auto& v : res) {
    cout << sz(v) << " " << v << endl;
  }

  return 0;
}
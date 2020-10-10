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

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        ++res;
        if (i > 0 && s[i - 1] == 'W') {
          ++res;
        }
      }
    }

    if (k == 0) {
      cout << res << endl;
      continue;
    }

    int first_w = s.find('W');
    int last_w = s.find_last_of('W');
    if (first_w == string::npos) {
      cout << 2 * k - 1 << endl;
      continue;
    }
    vector<int> groups;
    for (int i = first_w; i < last_w; ++i) {
      if (s[i] == 'W') {
        groups.emplace_back(0);
      } else {
        ++groups.back();
      }
    }
    sort(all(groups));
    for (int g : groups) {
      if (g == 0) continue;
      res += 2 * min(g, k) + (g <= k);
      k -= min(g, k);
      if (k == 0) break;
    }
    res += 2 * min(k, first_w);
    k -= min(k, first_w);
    res += 2 * min(k, n - 1 - last_w);

    cout << res << endl;
  }
  return 0;
}
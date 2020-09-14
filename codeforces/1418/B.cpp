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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<bool> locked(n);
    for (int i = 0; i < n; ++i) {
      bool b;
      cin >> b;
      locked[i] = b;
    }
    vector<int> unlocked;
    for (int i = 0; i < n; ++i) {
      if (!locked[i]) {
        unlocked.emplace_back(a[i]);
      }
    }
    sort(all(unlocked));
    for (int i = 0; i < n; ++i) {
      if (locked[i]) {
        cout << a[i] << " ";
      } else {
        cout << unlocked.back() << " ";
        unlocked.pop_back();
      }
    }
    cout << endl;
  }
  return 0;
}
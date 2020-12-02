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

int m, n;

bool ask(int x) {
  cout << x << endl;
  int res;
  cin >> res;
  if (res == 0) {
    exit(0);
  }
  return res == 1;
}

int main() {
  cin >> m >> n;
  vector<bool> truth(n);
  for (int i = 0; i < n; ++i) {
    truth[i] = ask(1);
  }
  int low = 1, high = m;
  int curr = 0;
  while (true) {
    int mid = (low + high) / 2;
    bool res = ask(mid) ^ !truth[curr];
    curr = (curr + 1) % n;
    if (res) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return 0;
}

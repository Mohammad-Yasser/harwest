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

Long square(Long x) { return x * x; }

Long f(Long x, int d) {
  Long c = x % d;
  return c * square(x / d + 1) + (d - c) * square(x / d);
}

Long delta(Long x, int d) { return f(x, d) - f(x, d + 1); }

struct Carrot {
  Long x;
  int d;
  bool operator<(const Carrot& other) const {
    return make_pair(delta(x, d), x) <
           make_pair(delta(other.x, other.d), other.x);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  priority_queue<Carrot> pq;
  Long res = 0;
  for (int i = 0; i < n; ++i) {
    Carrot c;
    cin >> c.x;
    c.d = 1;
    if (c.x == 1) {
      res += c.x;
      continue;
    }
    pq.emplace(c);
  }

  while (n < k) {
    ++n;
    auto nxt = pq.top();
    pq.pop();
    ++nxt.d;
    if (nxt.d == nxt.x) {
      res += nxt.x;
      continue;
    }
    pq.emplace(nxt);
  }
  while (!pq.empty()) {
    auto nxt = pq.top();
    pq.pop();
    res += f(nxt.x, nxt.d);
  }
  cout << res << endl;

  return 0;
}
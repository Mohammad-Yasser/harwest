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

template <class INT, int nLeaves>
struct BIT {
  const int kMaxSize = 1 << (int)ceil(log2(nLeaves + 1e-9));
  vector<INT> arr;
  INT size = 0;

  BIT() { arr.resize(kMaxSize); }

  INT get(int i) {
    i++;
    INT r = 0;
    while (i) {
      r += arr[i - 1];
      i -= i & -i;
    }
    return r;
  }

  INT get(int l, int r) {
    if (r < l) return 0;
    if (l == 0) return get(r);
    return get(r) - get(l - 1);
  }

  void add(int i, INT val = 1) {
    size += val;
    i++;
    while (i <= kMaxSize) {
      arr[i - 1] += val;
      i += i & -i;
    }
  }

  void insert(int x) { add(x, 1); }
  void erase(int x) { add(x, -1); }
};

const int A = 'z' - 'a' + 1;
const int N = 2e5 + 5;
queue<int> q[A];
BIT<int, N> bit;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    q[s[i] - 'a'].emplace(i);
    bit.insert(i);
  }
  reverse(all(s));
  Long res = 0;
  for (char c : s) {
    c -= 'a';
    bit.erase(q[c].front());
    res += bit.get(q[c].front());
    q[c].pop();
  }
  cout << res << endl;

  return 0;
}
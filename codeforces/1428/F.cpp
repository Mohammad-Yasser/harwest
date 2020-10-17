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

const int N = 5e5 + 5;

Long f(Long n) { return n * (n + 1) / 2; }
int arr[N];
int nxt[N];
Long res[N];
string s;
int n;

void buildFirstNextLarger() {
  nxt[n - 1] = n;
  for (int i = n - 2; i >= 0; --i) {
    int& fs = nxt[i];
    fs = i + 1;
    while (fs != n && arr[fs] < arr[i]) {
      fs = nxt[fs];
    }
  }
}

void buildArr() {
  int last = n;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      arr[i] = last - i;
    } else {
      last = i;
      arr[i] = 0;
    }
  }
}

void solve() {
  for (int i = n - 1; i >= 0; --i) {
    res[i] = f(arr[i]);
    res[i] += 1LL * (nxt[i] - i - arr[i]) * arr[i];
    if (nxt[i] == n) continue;
    res[i] += 1LL * arr[i] * arr[i];
    res[i] += res[nxt[i]];
    res[i] -= f(arr[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  cin >> n >> s;
  buildArr();
  buildFirstNextLarger();
  solve();
  cout << accumulate(res, res + n, 0LL) << endl;
  return 0;
}
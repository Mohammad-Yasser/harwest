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

const int N = 1e5 + 5;
int a[N];
vector<int> cols[4];
vector<pair<int, int>> res;
set<int> active_cols;
int lowest_target[N];
int next_row;

void build1() {
  for (int i : cols[1]) {
    res.emplace_back(next_row, i);
    lowest_target[i] = next_row;
    active_cols.emplace(i);
    ++next_row;
  }
}

void fail() {
  cout << -1 << endl;
  exit(0);
}

void build2() {
  for (int i : cols[2]) {
    auto it = active_cols.lower_bound(i);
    if (it == end(active_cols)) fail();
    res.emplace_back(lowest_target[*it], i);
    lowest_target[i] = lowest_target[*it];
    active_cols.erase(it);
    active_cols.emplace(i);
  }
}
int n;

void build3() {
  reverse(all(cols[3]));
  for (int i : cols[3]) {
    auto it = active_cols.lower_bound(i);
    if (it == end(active_cols)) fail();
    if (next_row == n) fail();
    res.emplace_back(next_row, i);
    res.emplace_back(next_row, *it);
    active_cols.erase(it);
    active_cols.emplace(i);
    ++next_row;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cols[a[i]].emplace_back(i);
  }

  build1();
  build2();
  build3();

  cout << sz(res) << endl;
  for (auto& [x, y] : res) {
    cout << n - x << " " << y + 1 << endl;
  }

  return 0;
}
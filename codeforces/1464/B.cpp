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

const int N = 1e5 + 5;

template <class INT, int kMaxSize>
struct BIT {
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
};

BIT<int, N> bit;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;
  Long x, y;
  cin >> x >> y;

  if (x > y) {
    for (char& c : s) {
      if (c != '?') c ^= 1;
    }
    swap(x, y);
  }

  Long curr = 0;
  Long ones = 0;
  vector<Long> cnt;
  for (int i = 0; i < sz(s); ++i) {
    cnt.emplace_back(ones);
    if (s[i] == '0') {
      curr += ones * y;
    } else {
      curr += (i - ones) * x;
      ++ones;
    }
  }
  Long res = curr;
  Long prevq = 0;

  for (int i = 0; i < sz(s); ++i) {
    if (s[i] != '?') continue;
    Long prev_ones = cnt[i] - prevq;
    Long next_ones = ones - 1 - cnt[i];
    Long prev_zeroes = i - prev_ones;
    Long next_zeroes = sz(s) - i - 1 - next_ones;
    curr += prev_ones * y - prev_zeroes * x + next_ones * x - next_zeroes * y;
    res = min(res, curr);
    ++prevq;
  }

  cout << res << endl;

  return 0;
}
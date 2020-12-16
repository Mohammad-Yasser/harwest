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

vector<int> values;

template <class INT, int kMaxSize>
struct BIT {
  vector<INT> arr;
  INT size = 0;
  BIT() { arr.resize(kMaxSize); }

  INT get(int x) {
    int i = lower_bound(all(values), x) - begin(values);
    // assert(i != sz(values) && values[i] == x);
    ++i;
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

  INT getSuffix(int l) { return size - get(l - 1); }

  void add(int x, INT val = 1) {
    size += val;
    int i = lower_bound(all(values), x) - begin(values);
    // assert(i != sz(values) && values[i] == x);
    ++i;
    while (i <= kMaxSize) {
      arr[i - 1] += val;
      i += i & -i;
    }
  }
};

int floordiv(int a, int b) {
  if (a >= 0) return a / b;
  return a / b - (a % b != 0);
}

int mod(int a, int m) {
  if ((a %= m) < 0) a += m;
  return a;
}

Long solve(const vector<int>& v, int length, int t) {
  t *= 2;
  vector<int> conc_v = v;
  for (int i = 0; i < sz(v); ++i) {
    conc_v.emplace_back(v[i] + length);
  }
  for (int& x : conc_v) {
    values.emplace_back(x % length);
    int rmod = mod(t - x, length);
    if (rmod != 0) {
      values.emplace_back(length - rmod - 1);
    }
  }
  values.emplace_back(length);
  sort(all(values));
  int r = sz(conc_v) - 1;
  int l = r;
  Long res = 0;
  Long curr_lc = 0;
  BIT<int, int(4e6 + 3)> bit;
  while (r > sz(v) - 1) {
    if (r != sz(conc_v) - 1 && l <= r) {
      bit.add(conc_v[r] % length, -1);
      curr_lc -= conc_v[r] / length;
    }
    l = min(l, r);
    Long rc = floordiv(t - conc_v[r], length);
    int rmod = mod(t - conc_v[r], length);
    while (r - l + 1 < sz(v) && t >= conc_v[r] - conc_v[l - 1]) {
      --l;
      bit.add(conc_v[l] % length, 1);
      curr_lc += conc_v[l] / length;
    }
    res += (rc + 1) * (r - l) + curr_lc;
    if (rmod != 0) {
      res += bit.getSuffix(length - rmod);
    }
    --r;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n, l, t;
  cin >> n >> l >> t;
  vector<int> a(n);
  cin >> a;

  cout << fixed << setprecision(10) << solve(a, l, t) / 4.0 << endl;

  return 0;
}
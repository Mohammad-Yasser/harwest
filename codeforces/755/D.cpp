#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000006;

template<class T>
struct BIT {
  vector<T> v;
  BIT(int s) {
    Resize(s);
  }
  BIT() {
  }
  void Resize(int s) {
    s = 1 << (int) ceil(log(1.0 * s) / log(2.) + 1e-9);
    v.resize(s);
  }
  T Get(int i) {
    i++;
    T r = 0;
    while (i) {
      r += v[i - 1];
      i -= i & -i;
    }
    return r;
  }
  void Add(int i, T val = 1) {
    i++;
    while (i <= (int) v.size()) {
      v[i - 1] += val;
      i += i & -i;
    }
  }
  int Find(T val) { // Find element at index ind.
    int s = 0;
    int m = v.size() >> 1;
    while (m) {
      if (v[s + m - 1] < val) val -= v[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }
};

int n, k;

int Shift(int x, int shift = k) {
  x += shift;
  if (x > n) x -= n;
  if (x < 1) x += n;
  return x;
}

pair<int, int> GetRange(int x, int y) {
  int beg, end;
  if (2 * k < n) {
    beg = Shift(x, -(k - 1));
    end = Shift(y, -1);
  } else {
    beg = Shift(y, 1);
    end = Shift(x, -(k + 1));
  }

  return {beg,end};
}

BIT<int> bit(N);

int GetCount(int x, int y) {
  if (y >= x) {
    return bit.Get(y) - bit.Get(x - 1);
  }
  return bit.Get(N - 1) - GetCount(y + 1, x - 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> k;
  int curr = 1;
  ll res = 1;
  for (int i = 1; i <= n; ++i) {
    int to = Shift(curr);
    auto range = GetRange(curr, to);
    int cnt = GetCount(range.first, range.second);
    res += cnt + 1;

    cout << res << ' ';
    bit.Add(curr);

    curr = to;
  }

}

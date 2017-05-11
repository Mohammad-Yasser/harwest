#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef tuple<int, int, int> State;

const int N = 1e5 + 5;

template<class T> inline void hash_combine(std::size_t & seed, const T & v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

int rx;

struct Hasher {
  inline size_t operator()(const tuple<int, int, int> & v) const {
    size_t seed = 0;
    ::hash_combine(seed, get<0>(v));
    ::hash_combine(seed, get<1>(v));
    ::hash_combine(seed, get<2>(v));
    seed ^= rx;
    return seed;
  }
};

const int OO = 1e7;

unordered_map<State, int, Hasher> memo;

int a, b;
int mult[N];
int n;
int Solve(int ind, int w, int h) {
  if (w >= a && h >= b) {
    return 0;
  }
  if (ind == n) return OO;

  if (memo.count(make_tuple(ind, w, h))) {
    return memo[make_tuple(ind, w, h)];
  }

  int res = OO;

  if (w < a) {
    res = min(res, 1 + Solve(ind + 1, min(1LL * OO, 1LL * w * mult[ind]), h));
  }
  if (h < b) {
    res = min(res, 1 + Solve(ind + 1, w, min(1LL * OO, 1LL * h * mult[ind])));
  }

  return memo[make_tuple(ind, w, h)] = res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  srand(time(0));

  rx = rand();

  int h, w;
  cin >> a >> b >> h >> w >> n;

  for (int i = 0; i < n; ++i) {
    cin >> mult[i];
  }

  sort(mult, mult + n);
  reverse(mult, mult + n);

  int res = min(Solve(0, w, h), Solve(0, h, w));

  if (res == OO) {
    res = -1;
  }
  cout << res;

}

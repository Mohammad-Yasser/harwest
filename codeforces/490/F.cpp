#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef long double Double;
typedef vector<int> vi;

const int N = 6003;

int r[N];

vector<int> adj[N];

int erased[N];

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

  // Finds element at index ind.
  int find(INT ind) {
    int s = 0;
    int m = kMaxSize >> 1;
    while (m) {
      if (arr[s + m - 1] < ind) ind -= arr[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }

  int lower_bound(int x) { return find(get(x - 1) + 1); }
};

BIT<int, N> bit;

int res = 0;
void dfs(int node, int parent) {
  auto it = bit.lower_bound(r[node]);
  if (it != N - 1) {
    erased[node] = it;
    bit.add(it, -1);
  }
  bit.add(r[node]);
  res = max(res, bit.size);
  for (int v : adj[node]) {
    if (v == parent) continue;
    dfs(v, node);
  }
  if (erased[node] != 0) {
    bit.add(erased[node]);
    erased[node] = 0;
  }
  bit.add(r[node], -1);
}

int n;

void compress() {
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(r[i]);
  }
  v.emplace_back(0);
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; ++i) {
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  bit.add(N - 1);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }
  compress();

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].emplace_back(y), adj[y].emplace_back(x);
  }

  int res = 0;

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() != 1) continue;
    dfs(i, -1);
    res = max(res, ::res);
  }

  cout << res - 1 << endl;

  return 0;
}

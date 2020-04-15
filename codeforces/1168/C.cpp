#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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
typedef vector<int> vi;

const int N = 3e5 + 5;
const int L = 19;

struct Query {
  int ind;
  int a, b;
};

vector<Query> queries[N];
bool ans[N];

int dist[L][L];

inline bool isSet(int x, int bit) { return (x >> bit) & 1; }

void update(int ind, int value) {
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      if (isSet(value, i) && isSet(value, j)) {
        dist[i][j] = ind;
      }
    }
  }
  for (int i = 0; i < L; ++i) {
    if (!isSet(value, i)) continue;
    for (int j = 0; j < L; ++j) {
      if (!isSet(value, j)) continue;
      for (int k = 0; k < L; ++k) {
        dist[i][k] = min(dist[i][k], dist[j][k]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      dist[i][j] = N;
    }
  }

  int n, q;
  cin >> n >> q;
  vector<int> v(n);

  for (int& x : v) {
    cin >> x;
  }

  for (int i = 0; i < q; ++i) {
    Query query;
    cin >> query.a >> query.b;
    --query.a, --query.b;
    query.ind = i;
    queries[query.a].emplace_back(query);
  }

  for (int i = n - 1; i >= 0; --i) {
    update(i, v[i]);
    for (auto& query : queries[i]) {
      for (int u = 0; u < L; ++u) {
        if (!isSet(v[i], u)) continue;
        for (int z = 0; z < L; ++z) {
          if (!isSet(v[query.b], z)) continue;
          if (dist[u][z] <= query.b) {
            ans[query.ind] = true;
            break;
          }
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "Shi" : "Fou") << endl;
  }

  return 0;
}
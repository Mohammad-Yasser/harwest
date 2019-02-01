#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

int nxt[N];
int score[N];

struct Envelope {
  int d, w;
  Envelope(int d, int w) :
    d(d), w(w) {
  }
  bool operator<(const Envelope& other) const {
    return make_pair(w, d) > make_pair(other.w, other.d);
  }
};

multiset<Envelope> in[N], out[N];

void buildNxt() {
  multiset<Envelope> curr;
  for (int i = 0; i < N; ++i) {
    nxt[i] = i + 1;

    curr.insert(in[i].begin(), in[i].end());

    if (!curr.empty()) {
      nxt[i] = curr.begin()->d + 1;
      score[i] = curr.begin()->w;
    }

    for (auto& env : out[i]) {
      curr.erase(curr.find(env));
    }
  }
}

const int M = 201;
Long memo[N][M];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;

  while (k--) {
    int s, t, d, w;
    cin >> s >> t >> d >> w;
    in[s].emplace(d, w);
    out[t].emplace(d, w);
  }

  buildNxt();

  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= m; ++j) {
      memo[i][j] = memo[nxt[i]][j] + score[i];
      if (j != 0) {
        memo[i][j] = min(memo[i + 1][j - 1], memo[i][j]);
      }
    }
  }

  cout << memo[0][m] << endl;

}
